#include "count_words.h"

int main(int argc, char *argv[], char *envp[]) {

    unsigned int *character_instances = NULL;
    int i; 
    size_t count;
    WEIGHTED_CHAR *ordered_table;
   
    if (argc < 2) {

        printf (" Usage: ");
        printf ("   ./char_stats [filename]");
        printf (" \n");
        return -1;
    }
    

    character_instances = get_word_frequencies_from_file(argv[1], &count); 
    if (character_instances == NULL)
        return -1;

    //    pp_frequency_table(character_instances, count, 80); 
    lowercase_statistics(character_instances);
    flatten_statistics_to_alpha(character_instances, &count);
    pp_alpha_frequency_table(character_instances, count, 80);
    ordered_table = alpha_frequency_table_to_weighted_char(
            character_instances, count);

    return 0;
}
