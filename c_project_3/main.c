#include "file.h"


int main(void)
{
  char* file_content = NULL;  

  KeyValue* pairs = NULL;
  int count = 0;

  file_load("file.ini", &file_content);
  
  parse_ini(file_content, &pairs, &count);

  printf("Załadowane klucze i wartości:\n");
  for (int i = 0; i < count; i++) {
    printf("%s = %s\n", pairs[i].key, pairs[i].value);
  }

  return 0;
}