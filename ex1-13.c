#include<stdio.h>
#define MAXLEN 20
#define OUT 0
#define IN 1

int test(int arr[MAXLEN]){
  for (int i = 0; i<MAXLEN; ++i){
    printf("%2d:\t%2d\n",(i+1), arr[i]);
  }
  return 0;
}

int main(void){
  /*
   * Input and lenght
   */
  int lenW[MAXLEN];
  for (int i = 0; i<MAXLEN; ++i){
    lenW[i] = 0;
  }
  //input und count
  int c;
  int index = 0;
  int mode = OUT;
  while((c = getchar()) != EOF){
    if((c == ' ' || c == '\t' || c == '\n') && (mode == IN)){
      ++index;
      mode = OUT;
    }
    else if((c != ' ' || c != '\t' || c != '\n') && (mode == OUT)){
      mode = IN;
      ++lenW[index];
    }
    else if((c != ' ' || c != '\t' || c != '\n') && (mode == IN)){
      ++lenW[index];
    }
  }
  test(lenW);
  return 0;
}
