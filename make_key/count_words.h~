
#ifndef COUNT_WORDS_H
#define COUNT_WORDS_H
#warning "wtf"

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define PRINTABLE_BEGIN 33
#define PRINTABLE_CHARACTERS 127-PRINTABLE_BEGIN
#define BUFFER_SIZE 1024

#define ALPHA_BEGIN 32
#define ALPHA_END 58
#define LOWERCASE_LOCATION 32

/* Data Structures */
typedef struct _weighted_character {
    char character;
    float weight;
} WEIGHTED_CHAR;

/* constants */
/* function prototypes */
unsigned int * get_word_frequencies_from_file(char *filename, size_t *count);

void lowercase_statistics(unsigned int *character_instances);
void flatten_statistics_to_alpha(unsigned int *character_instances, 
        size_t *count);

void pp_frequency_table(unsigned int *character_instances, size_t count, 
        int cols);
void pp_alpha_frequency_table(unsigned int *character_instances, size_t count,
        int cols);


WEIGHTED_CHAR * alpha_frequency_table_to_weighted_char(
        unsigned int *character_instances, size_t count);

void quicksort_weighted_chars(WEIGHTED_CHAR *arr, int left, int right);

#endif 
