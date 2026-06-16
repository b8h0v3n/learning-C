#include<stdio.h>
#define MAXLEN 1000
#define IN 1
#define OUT 0

int my_getline(char arr[], int max){
  int len = 0;
  int mode = OUT;
  int c;
  while((c = getchar()) != EOF && c != '\n'){
    if((c != ' ' && c != '\t') && mode == OUT){
      mode = IN;
      arr[len] = c;
      ++len;
    }
    else if((c != ' ' && c != '\t') && mode == IN){
      arr[len] = c;
      ++len;
    }
    else if((c == ' ' && c == '\t') && mode == IN){
      mode = OUT;
      arr[len] = c;
      ++len;
    }
    else
      ;
  }
  switch (arr[len]){
    case '\t':
      arr[len] = '\n';
    case ' ':
      arr[len] = '\n';
    default:
      ++len;
      arr[len] = '\0';
  }
 //returns the amount of characters in the string
  return (len - 1);
}

int main(void){
  char line[MAXLEN];
  int len;
  while((len = my_getline(line, MAXLEN)) != 0){
    printf("%s", line);
    printf("%d", len);
  }
}

