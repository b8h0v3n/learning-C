#include <stdio.h>

//Aufgabe 1.5.1 1-6
int ex1(void){
  int c;
  printf("%d\n", (c = getchar()) != EOF);
}
//Aufgabe 1.5.1 1-7
int ex2(void){
  printf("%d\n", EOF);
}

int main(void){
  ex1();
  ex2();
}
