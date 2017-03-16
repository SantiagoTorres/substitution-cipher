#include "create_key.h"
#include "count_words.h"

char *create_key(void) {
    
    /* allocate an alphbabet of information */
    WEIGHTED_CHAR *key_gen = malloc(sizeof(*key_gen)*ALPHA_END - ALPHA_BEGIN);
    char *key = malloc(ALPHA_END - ALPHA_BEGIN);
    int i;

    for (i = 0; i < ALPHA_END - ALPHA_BEGIN; i++) {
        key_gen[i].character = i + PRINTABLE_BEGIN + ALPHA_BEGIN;
        key_gen[i].weight = get_random_float(); 

    }

    quicksort_weighted_chars(key_gen, 0, ALPHA_END - ALPHA_BEGIN -1);

    for (i = 0; i < ALPHA_END - ALPHA_BEGIN; i++)
        key[i] = key_gen[i].character;

    return key;
}


void dump_key(char *filename, char *key, size_t size) {

    FILE *fp;
    size_t count;

    fp = fopen(filename, "wb");

    if(!fp)
        return;

    count = fwrite( key, sizeof(char), size, fp);

    if (count != size)
        printf("error writing key\n");

    fclose(fp);
    return;
}


char *load_key(char *filename) {

    FILE *fp;
    size_t count = ALPHA_END - ALPHA_BEGIN;
    size_t actually_read;
    char *key = malloc(sizeof(*key)*count);

    fp = fopen(filename, "rb");

    if (!fp)
        return NULL;

    actually_read = fread( key, sizeof(char), count, fp);

    if (actually_read != count)
        printf("[!!] Error  reading key\n");

    return key;
}


float get_random_float(void) {
    
    int fp;
    unsigned int length = sizeof(float);
    float result;
    int i = 0;

    fp = open("/dev/random",O_RDONLY);

    if (!fp)
        return 0;

    while(i<length) {
        i += read(fp, (void *)(&result) + i, length - i);
    } 
    close(fp);
    return result;
}

char *invert_key(char *key) {

    size_t count = ALPHA_END - ALPHA_BEGIN;
    char *inverted_key = malloc(sizeof(*inverted_key) * count);
    int i;
    for(i = 0; i < count; i++) {
        inverted_key[key[i]] = i;

   }
   
   return inverted_key; 
}
