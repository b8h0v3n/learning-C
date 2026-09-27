#include <stdio.h>
int ex1(void){
  int c; 
  int tab, space, newline = 0;

  while ((c = getchar()) != EOF){
    if (c == '\n')  ++newline;
    if (c == ' ')  ++space;
    if (c == '\t')  ++tab;
  }
  printf("\n\n\nNewlines: %d\nTabs: %d\nSpaces: %d\n", newline, tab, space);
}

int ex2(void){
  int c;
  int lastc;
  while ((c = getchar()) != EOF){
    if (c == ' ' && lastc == ' ')
      ;
    else putchar(c);
    lastc = c;
  }
}

int ex3(){
  int c;
  while ((c = getchar()) != EOF){
    if (c == '\t'){
      c = '\\';
      putchar(c);
      c = 't';
      putchar(c);
    } else if (c == '\\'){
      c = '\\';
      putchar(c);
      c = '\\';
      putchar(c);
    } else if (c == '\b'){
      c = '\\';
      putchar(c);
      c = 'b';
      putchar(c);
    } 
    else putchar(c);
  }
}

int main(){
  ex3();
}
