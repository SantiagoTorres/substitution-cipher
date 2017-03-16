#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int encrypt_file(char *plain_filename, char *cipher_filename, char *key, 
        char filter);
void decrypt_file(char *cipher_filename, char *plain_filename, char *key);
char is_alpha_to_upper(char candidate);
