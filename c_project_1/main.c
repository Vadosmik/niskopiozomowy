#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char str1[] = "^^Hel1o*_W0rld$";

char *conn_string(char *str3, char *str2)
{
  uint16_t len1 = strlen(str3);
  uint16_t len2 = strlen(str2);
  char *str = (char *)malloc(len1 + len2 + 1);
  memcpy(str, str3, len1);
  memcpy(str + len1, str2, len2);
  str[len1 + len1] = 0;

  return str;
}

/* nie wiem jak 
char *convertDigitToWord(char ch)
{
  char *out;
  switch (ch)
  {
  case 48:
    out = "zero";
    break;
  case 49:
    out = "one";
    break;
  case 50:
    out = "two";
    break;
  default:
    break;
  }
  return out;
}
*/

char processChar(char ch, int change_case)
{
    if (change_case == 1 && (ch >= 65 && ch <= 90)) 
    {
        return ch + 32;
    }
    else if (change_case == 2 && (ch >= 97 && ch <= 122))
    {
        return ch - 32;
    }
    return ch;
}

char *replaceFnc(const char *input_str, char sep, int change_case)
{
  static char answer[sizeof(str1)];
  int is_separator_needed = 0;
  int i = 0;

  while(*input_str)
  {
    if ((*input_str >= 65 && *input_str <= 90) || (*input_str >= 97 && *input_str <= 122))
    {
      answer[i++] = processChar(*input_str, change_case);
      is_separator_needed = 1;
    }
    else if (*input_str >= 48 && *input_str <= 57) 
    {
      answer[i++] = *input_str;
    } 
    else
    {
      if (is_separator_needed)
      {
        answer[i++] = sep;
        is_separator_needed = 0;
      }
    }
    input_str++;
  }
  if (answer[i - 1] == sep) {
    i--;
  }
  answer[i] = '\0'; 
  return answer;
}

int main(void) {
  const char *input_str = str1;
  
  printf("%s\n", replaceFnc(input_str, ' ', 1));

  printf("%s\n", replaceFnc(input_str, ' ', 2));

  return 0;
}