#include "create_key.h"
#include "count_words.h"

int main(int argc, char *argv[], char *envp[]) {
    
    int i;
    char *key;
    char *filename = NULL;

    if (argc < 2) {
        printf(" Usage:\n");
        printf(" create_key [filename]\n");
        return 1;
    }
    
    filename = argv[1];

    key = create_key();
    dump_key(filename, key, ALPHA_END - ALPHA_BEGIN);
    free(key);

    key = load_key(filename);

    for (i = 0; i < ALPHA_END - ALPHA_BEGIN; i++)
        printf(" %c -> %c\n", i + PRINTABLE_BEGIN + ALPHA_BEGIN, key[i]);

    return 0;
}
