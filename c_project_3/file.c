#include "file.h"

//---------------------------------------------------------------------------------------------------------------------

bool file_save(const char *name, char **bytes)
{
  FILE *fp = fopen(name, "wb");
  if (fp == NULL)
    return false;

  fprintf(fp, "%s", *bytes);
  fclose(fp);
}

int file_load(const char *name, char **bytes)
{
  size_t size = 0;
  FILE *fp = fopen(name, "rb");
  if (fp == NULL)
  {
    *bytes = NULL;
    return -1;
  }
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  *bytes = (char *)malloc(size + 1);
  if (size != fread(*bytes, sizeof(char), size, fp))
  {
    free(*bytes);
    return -2;
  }
  fclose(fp);
  (*bytes)[size] = 0;
  return size;
}

//---------------------------------------------------------------------------------------------------------------------

bool data_save(const char *name, uint8_t **bytes, size_t size)
{
  FILE *fp = fopen(name, "wb");
  if (fp == NULL)
    return false;
  fwrite(*bytes, sizeof(uint8_t), size, fp);
  fclose(fp);
}

int data_load(const char *name, uint8_t **bytes)
{
  size_t size = 0;
  FILE *fp = fopen(name, "rb");
  if (fp == NULL)
  {
    *bytes = NULL;
    return -1;
  }
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  *bytes = (char *)malloc(size);
  if (size != fread(*bytes, sizeof(char), size, fp))
  {
    free(*bytes);
    return -2;
  }
  fclose(fp);
  return size;
}

//---------------------------------------------------------------------------------------------------------------------

void putbytes(uint8_t *bytes, size_t size)
{
  for(size_t i = 0; i < size; i++)
  {
    putchar(*bytes);
    bytes++;
  }
}

//---------------------------------------------------------------------------------------------------------------------

char* trim(char* str) {
    char* end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str; // Jeśli pusta
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    return str;
}

int parse_ini(const char* data, KeyValue** pairs, int* count) {
  char* line;
  char* buffer = strdup(data);
  *pairs = NULL;
  *count = 0;


  line = strtok(buffer, "\n");
  while(line != NULL) {
    char* trimmed_line = trim(line);

    if (trimmed_line[0] == '\0' || trimmed_line[0] == '#') {
      line = strtok(NULL, "\n");
      continue;
    }

    char* comment = strchr(trimmed_line, '#');
    if (comment) {
      *comment = '\0';
    }

    char* delimiter = strchr(trimmed_line, '=');
    if (!delimiter) {
      fprintf(stderr, "Nieprawidłowy format linii: %s\n", line);
      line = strtok(NULL, "\n");
      continue;
    }

    *delimiter = '\0';
    char* key = trim(trimmed_line);
    char* value = trim(delimiter + 1);

    *pairs = realloc(*pairs, (*count + 1) * sizeof(KeyValue));
    if (*pairs == NULL) {
      perror("Nie udało się alokować pamięci");
      free(buffer);
      return -1;
    }

    // to
    snprintf((*pairs)[*count].key, sizeof((*pairs)[*count].key), "%s", key);
    snprintf((*pairs)[*count].value, sizeof((*pairs)[*count].value), "%s", value);
    
    (*count)++;
    line = strtok(NULL, "\n");

  }

  free(buffer);
  return 0;
}