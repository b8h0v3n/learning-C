#include<stdio.h>

#define MAXLEN 1000
#define TABSTOP 8

char line[MAXLEN];
int myGetLine(void);
int newPrint(void);

int main(void){
  extern char line[];
  int len;
  while((len = myGetLine()) > 0){
  //  for(int i = 0; i<len; ++i){ why doesn't this work=
  //    putchar(line[i]);
  //  } 
    newPrint();
  }
  return 0;
}

//MAXLINE exceeded not covered
int myGetLine(){

  int col = 0, c = 0, step = 0, nCol = 0, len = 0;
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
      len = col;
      ++col;
      break;
    }
    else{
      line[col] = c;
      ++col;
    }
  }
  line[col] = '\0';

  return len;
}

int newPrint(void){
  extern char line[];
  int i = 0;

  while(line[i] != '\0'){
    putchar(line[i]);
    ++i;
  }
  
}
