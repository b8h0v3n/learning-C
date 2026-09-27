#include <stdio.h>

// define symbolic constants
#define LOWER 0
#define UPPER 300
#define STEP 20

//fahrenheit to celsius converter
int main(){
  printf("Fahr\tCelsius\n");
  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP){
    printf("%3d\t%6.2f\n", fahr, (fahr - 32)*(5.0/9.0));
  }

}
// %3d decimal number, which is 3 characters wide
// %6.2f floating number, which is 6 characters wide an has 2 decimal points
