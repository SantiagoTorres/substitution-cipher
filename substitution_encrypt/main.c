#include "create_key.h"
#include "count_words.h"

int main(int argc, char *argv[], char *envp[]) {
    
    int i;
    char *key;
    
    if (argc < 4) {
        printf ("Usage: \n");
        printf ("  encrypt [plaintext] [cipher] [key]\n");
        return -1;
    }

    key = load_key(argv[3]);
    
    if(!key)
        printf("[!!] Couln't load key!!!\n");

    encrypt_file(argv[1], argv[2], key, 1);

    return 0;
}
