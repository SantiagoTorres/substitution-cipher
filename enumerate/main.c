#include <stdio.h>
#include <stdlib.h>
#include "break_utils.h"

void increase_count(char *buffer, int keylength, char *overflow) {

    buffer[0] += 1;
    if (buffer[0] > 25) {
        buffer[0] = 0;
        if(keylength == 1)
            *overflow = 1;
        return increase_count(buffer + 1, keylength - 1, overflow);
    }
}

int main(int argc, char *argv[])
{
    
    char *enumeration_buffer; 
    char plaintext_buffer[] = "aloofamorph\0ousan\0alogu\0eanec\0dotea\0ntici\0pation\0antipathyapatheticappointmentapprovalattenuateblackout";
    int keylength;
    int i;
    long j;
    char overflow = 0;

    if (argc < 2) {
        printf("Usage:\n");
        printf("\t./enumerate [keylength]\n");
        return 1;
    }

    keylength = atoi(argv[1]);
    
    if (keylength < 1) {
        printf("Keylength must be between 1 and 40\n");
        return 1;
    }
    
    enumeration_buffer = malloc(sizeof(*enumeration_buffer) * keylength);

    for (i = 0; i < keylength; i++)
        enumeration_buffer[i] = 0;

    while (overflow == 0) {
        increase_count(enumeration_buffer, keylength, &overflow); 
        verify_plaintext(plaintext_buffer);
    }
     
    return 0;
}


