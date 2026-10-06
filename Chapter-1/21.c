/*
 *   gcc -Wall -Wextra -g -O0 ex1-21.c -o entab
 */
#include <stdio.h>
#define MAXLEN 1000 //max index = 999
#define OVERFLOW 2000
#define TABSTOP 8

int getLine2(char l[]);
int entab(char in[],char out[]);

int main() {
  char line[MAXLEN];
  char line2[MAXLEN];
  int len = 0;
  while ((len = getLine2(line)) > 1){
    if (len == 999){
      entab(line, line2);
      printf("%s", line2);
      getLine2(line);
    }
    entab(line, line2);
    printf("%s\n", line2);
  }
  return 0;
}

// \n doesnt get terminated with \0
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
//Overflow isnt handled ?
//Buggy: for loop doesnt end. character after spaces gets lost
int entab(char in[], char out[]){
  int j;
  int col2 = 0;
  for (int i = 0; i<MAXLEN-1;++i){
    switch (in[i]){
      case ' ':
        //count spaces
        int spaces = 0;
        j=i;
        while(in[j] == ' '){
          ++spaces;
          ++j;
        }
        while(spaces > 0){
          if(((i+1) % TABSTOP) != 0){
            out[col2] = ' ';
            ++col2;
            ++i;
            --spaces;
          }
          else if(((i+1) % TABSTOP != 0) && ((spaces - TABSTOP) >= 0)){
            out[col2] = '\t';
            i = i + TABSTOP;
            ++col2;
            spaces = spaces - TABSTOP;
          }
          else{
            out[col2] = ' ';
            ++col2;
            ++i;
            --spaces;
          }
        }
        out[col2] = in[i];
        break;
      case '\0':
        out[col2] = '\0';
        return col2;
      default:
        out[col2] = in[i];
        ++col2;
        break;
    }
  }
  return col2;
}
