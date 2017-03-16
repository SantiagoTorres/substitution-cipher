#ifndef CREATE_KEY_H
#define CREATE_KEY_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


char *create_key(void);
float get_random_float(void);
void dump_key(char *filename, char *key, size_t size);
char *load_key(char *filename);
char *invert_key(char *key);

#endif
