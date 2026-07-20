#include<stdio.h>
#define MAXLEN 1000
#define IN 1
#define OUT 0

int my_getline(char arr[], int max){
  int len = 0;
  int mode = OUT;
  int c;
  while((c = getchar()) != EOF && c != '\n' && len < (MAXLEN - 1)){
    if((c != ' ' && c != '\t') && mode == OUT){
      mode = IN;
      arr[len] = c;
      ++len;
    }
    else if((c != ' ' && c != '\t') && mode == IN){
      arr[len] = c;
      ++len;
    }
    else if((c == ' ' || c == '\t') && mode == IN){
      mode = OUT;
      arr[len] = c;
      ++len;
    }
    else
      ;
  }
  switch (c){
    case '\n':
      arr[len] = '\n';
    case EOF:
      arr[len] = '\n';
    default:
      ++len;
      arr[len] = '\0';
  }
 //returns the amount of characters in the string
  return (len - 1);
}
// indizes cooked
int reverse(char string[], char rString[]){
  int indexS= 0;
  int indexR = 0;
  while (string[indexS] != '\0'){
    ++indexS;
  }
  printf("%d\n", indexS);
  while (indexS != 0){
    rString[indexR] = string[indexS];
    --indexS;
    ++indexR;
  }
  ++indexR;
  printf("%d\n", indexR);
  rString[indexR] = '\0';
  return 0;
}

int main(void){
  char line[MAXLEN];
  char rString[MAXLEN];
  int len;
  while((len = my_getline(line, MAXLEN)) != 0){
    printf("%s\n", line);
    printf("%d\n", reverse(line, rString));
//    printf("%s\n", rString);
  }
}


