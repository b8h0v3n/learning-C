// entab returns the amount of elements in line[] except '\0'
#include<stdio.h>
#define TABSTOP 8
#define MAXLINE 1000

int getSpaces(){
  int spaces, c;
  while ((c = getchar()) == ' '){
    ++spaces;
  }
  return spaces;
}

int entab(char line[]){
  int c, len;
  int column = 0;
  while ((c=getchar()) != EOF && c != '\n'){
    switch(c){
      case ' ':
        int spaces = getSpaces();
        while((spaces % TABSTOP) != 0){
          line[column] = ' ';
          ++column;
          --spaces;
        }
        for(int i = 0;i < spaces/TABSTOP; i=(i+TABSTOP)){
          line[column] = '\t';
          ++column;
        }
      default:
        line[column] = c;
        ++column;
    }
  }
  if(column == 0 && c == '\n'){
    return 0;
  }
  else if(c == '\n'){
    line[column] = '\n';  
    ++column;
    len = column;
    return len;
  }
  else{ //in case EOF

    return column;
  }
}

int main(void){
  int len, i = 0;
  char line[MAXLINE];
  while(len = entab(line) > 0){
    while(line[i] != '\0'){
      putchar(line[i]);
      ++i;
    }
    i = 0;
  }
}


