#include<stdio.h>

#define MAXLEN 1000
#define TABSTOP 8

char line[MAXLEN];
int myGetLine(void);

int main(void){
  extern char line[];
  int len;
  while((len = myGetLine()) > 0){
    for(int i = 0; i<len; ++i){
      putchar(line[i]);
    } 
  }
  return 0;
}

int myGetLine(){

  int col = 0, c = 0, step = 0, nCol = 0;
  extern char line[];

  while((c = getchar()) != EOF){

    if(c == '\t'){
      step = TABSTOP - (col % TABSTOP);
      nCol = col + step;
      while(col != nCol){
        line[col] = ' ';
        ++col;
      }
    }
    else if(c == '\n'){
      line[col] = '\n';
      return col;
    }
    else{
      line[col] = c;
      ++col;
    }
  }
}
