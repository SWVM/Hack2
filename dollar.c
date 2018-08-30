#include <stdio.h>
#include <stdlib.h>
#define JPY_PER_USD  76.80
#define POUND_PER_USD  0.6

int main(int argc, char const *argv[]) {

  printf("Please input the total amount of US Dollars:\n");

  double USD = 0;
  scanf("%lf", &USD);
  USD *= 0.9;

  double JPY = (USD/2) * JPY_PER_USD;
  double POUND = (USD/2) * POUND_PER_USD;
  printf("You get %f British Pounds and %f Japanese JPY.\n", JPY, POUND);

    return 0;
}
