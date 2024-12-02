#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>


#ifndef _FILE_H_
#define _FILE_H_

typedef struct {
  char key[50];
  char value[50];
} KeyValue;


//---------------------------------------------------------------------------------------------------------------------

bool file_save(const char *name, char **bytes);
int file_load(const char *name, char **bytes);
bool data_save(const char *name, uint8_t **bytes, size_t size);
int data_load(const char *name, uint8_t **bytes);
void putbytes(uint8_t *bytes, size_t size);

int parse_ini(const char* data, KeyValue** pairs, int* count);

//---------------------------------------------------------------------------------------------------------------------

#endif