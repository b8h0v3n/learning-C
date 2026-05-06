#include <stdio.h>

//define symbolic constants
#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
  float celsius;
  printf("Celsius\tFahrenheit\n");
  for (celsius = LOWER; celsius <= UPPER; celsius += STEP){
    printf("%3.0f\t%3.0f\n",celsius, (celsius * (9.0/5.0) + 32));
  }
}

