#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// static char str1[] = "Hello1";
// char *str2 = "Hello2";

char *conn_string(char *str1, char *str2)
{
  uint16_t len1 = strlen(str1);
  uint16_t len2 = strlen(str2);
  char *str = (char *)malloc(len1 + len2 + 1);
  memcpy(str, str1, len1);
  memcpy(str + len1, str2, len2);
  str[len1 + len1] = 0;

  // uint16_t i = 0;
  // while(*str1)
  // {
  //   str[i] = *str1;
  //   str1++;
  //   i++;
  // }
  // while(*str2)
  // {
  //   str[i] = *str2;
  //   str2++;
  //   i++;
  // }
  // str[i] = '\0';
  return str;
}

int main(void)
{
  char *str_a = "connect";
  char *str_b = " string";
  char *str_out = conn_string(str_a, str_b);
  printf("%s", str_out);
  return 0;
}