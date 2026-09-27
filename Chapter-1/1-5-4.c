#include <stdio.h>
#define IN 1 
#define OUT 0

int ex2(){
  int c;
  int lastc = 0;
  while ((c = getchar()) != EOF){
    if ((c == ' ' || c == '\t') && (lastc != ' ' && lastc != '\t')){
      putchar('\n');
      lastc = ' ';
    } else if (c != '\t' && c != ' ') {
      putchar(c);
      lastc = c;
    }
  }
  return 1;
}


int main(void){
  ex2();
  return 1;
}
