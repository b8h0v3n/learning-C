/*
 *   gcc -Wall -Wextra -g -O0 ex1-21.c -o entab
 */
#include <stdio.h>
#define MAXLEN 1000 //max index = 999
#define OVERFLOW 2000

int getLine2(char l[]);

int main() {
  char line[MAXLEN];
  int len = 0;
  while ((len = getLine2(line)) > 1){
    if (len == 999){
      printf("%s", line);
      getLine2(line);
    }
    printf("%s\n", line);
  }
  return 0;
}


int getLine2(char l[]) {
  int col = 0;
  int c = 0;
  while (col < (MAXLEN-1)) { 
    c = getchar();
    switch (c){
      case ' ':
        l[col] = c;
        ++col;
        break;
      case '\n':
        l[col] = c;
        ++col;
        l[col] = '\0';
        return col;
      case EOF:
        l[col] = '\0';
        return col;
      default:
        l[col] = c;
        ++col;
        break;
    }
  }
  l[col] = c;
  return col;
}
