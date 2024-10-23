#include <stdio.h>

char str1[] = "^^Hel1o*_W0rld$";

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
  static char answer[100];
  int is_separator_needed = 0;
  int i = 0;

  while(*input_str)
  {
    if ((*input_str >= 48 && *input_str <= 57) || (*input_str >= 65 && *input_str <= 90) || (*input_str >= 97 && *input_str <= 122))
    {
      answer[i++] = processChar(*input_str, change_case);
      is_separator_needed = 1;
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