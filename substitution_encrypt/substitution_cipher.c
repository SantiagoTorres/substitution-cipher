#include "substitution_cipher.h"
#include "create_key.h"
#include "count_words.h"

// char filter tells us whether we should strip all non alpha chars or not.
int encrypt_file(char *plain_filename, char *cipher_filename, char *key, 
        char filter) {

    FILE *cipher_fp, *plaintext_fp;
    char buffer[1024];
    size_t read_count, write_count;
    char cipher_char;
    int i;
    char is_alpha;

    cipher_fp = fopen(cipher_filename, "wt");

    if(!cipher_fp)
        return -1;
    plaintext_fp = fopen(plain_filename, "rt");

    if (!plaintext_fp) {
        fclose(cipher_fp);
        return -1;
    }

    do{
        read_count = fread( buffer, sizeof(char), 1024, plaintext_fp);

        // we write byte by byte to allow filtering.
        for (i = 0; i < read_count; i++) {
            cipher_char = is_alpha_to_upper(buffer[i]); 
            if (cipher_char){
                cipher_char -= PRINTABLE_BEGIN;
                cipher_char -= ALPHA_BEGIN;
                write_count = fwrite(&key[cipher_char], sizeof(char),
                        1, cipher_fp);
            } else if (!filter) {
                write_count = fwrite(&buffer[i], sizeof(char), 1, cipher_fp);
            }
         
        }
    } while(read_count);
    
    return 0;
}

void decrypt_file(char *cipher_filename, char *plain_filename, char *key) {

    FILE *cipher_fp, *plaintext_fp;
    char buffer[1024];
    size_t read_count, write_count;
    char cipher_char;
    int i;
    char *forwards_key = key;
    char is_alpha;

    cipher_fp = fopen(cipher_filename, "rt");

    key = invert_key(forwards_key);
    for (i = 0; i < ALPHA_END - ALPHA_BEGIN; i++)
        printf(" %c -> %c -> %c\n", i + PRINTABLE_BEGIN + ALPHA_BEGIN, forwards_key[i], key[i]);
    free(forwards_key);

    if(!cipher_fp)
        return;
    plaintext_fp = fopen(plain_filename, "wt");

    if (!plaintext_fp) {
        fclose(cipher_fp);
        return;
    }

    do{
        read_count = fread( buffer, sizeof(char), 1024, cipher_fp);

        // we write byte by byte to allow filtering.
        for (i = 0; i < read_count; i++) {
            cipher_char = is_alpha_to_upper(buffer[i]); 
            if (cipher_char){
                cipher_char -= PRINTABLE_BEGIN;
                cipher_char -= ALPHA_BEGIN;
                write_count = fwrite(&key[cipher_char], sizeof(char),
                        1, plaintext_fp);
            } 
        }
    } while(read_count);
    
    return;
}

char is_alpha_to_upper(char candidate) {
    
    char alpha_start = PRINTABLE_BEGIN + ALPHA_BEGIN;
    char alpha_end = PRINTABLE_BEGIN + ALPHA_END - 1;
    if (candidate >= alpha_start && candidate <= alpha_end)
        return candidate;

    candidate -= LOWERCASE_LOCATION;

    if (candidate >= alpha_start && candidate <= alpha_end)
        return candidate;

    return 0;

}
