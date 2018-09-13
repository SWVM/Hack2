/*////////////////////////////////////////////////////////////////////////
//  Author: Li Linhan
//
//
//  Date:2018 Sept.11
//  Description: this program reads inputs from command line
//              and prints an amortization table for 401(k) accounts
//  Inputs(respectively): • initial balance
//                        • monthly contribution amount
//                        • average annual rate of return
//                        • average annual rate of inflation
//                        • years until retirement
//  Error codes:  1 --the rate is out of range
//                2 --the time(in years) entered is out of range
//                3 --the annually contribution is over 18500 dollar
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

  if (argc != 6) {
    printf("Arguments(respectively): • initial balance\n\
                                  • monthly contribution amount\
                                  • average annual rate of return\
                                  • average annual rate of inflation\
                                  • years until retirement");
    return 0;
  }

//    delare variables
  double balance = atof(argv[1]);
  double contribution_per_month = atof(argv[2]);
  double rate_of_return = atof(argv[3]);
  double rate_of_inflation = atof(argv[4]);
  int instance_untile_retirement = atoi(argv[5]) * 12;
  double adjusted_rate = ((1 + rate_of_return)/(1 + rate_of_inflation) - 1) / 12;
  double total_deposit = balance + (instance_untile_retirement * contribution_per_month);
  double interest = 0.0;


//    check to validate the inputs
  if (rate_of_return < 0 ||rate_of_inflation < 0 ||\
      rate_of_return > 1 ||rate_of_inflation > 1) {
    printf("Rates have to be greater than 0 and smaller than 1 !\n");
    return 1;
  }
  if (instance_untile_retirement < 0) {
    printf("The number of years have to be positive!\n");
    return 2;
  }
  if (contribution_per_month > (18500.0 / 12)) {
    printf("The annual contribution cannot exceed 18500!\n");
    return 3;
  }


//    calculation and printing
  printf("Month\tInterest\t\tBalance\n");//print the header of the table
  for (int i = 1; i < instance_untile_retirement + 1; i++) {

    interest = balance * adjusted_rate;
    balance += contribution_per_month + interest;
    printf("%d\t$ %.2lf  \t\t$ %.2lf\n", i, interest, balance);
  }

  printf("Total Interest Earned: $ %lf\n", balance - total_deposit);
  printf("Total Nest Egg: $ %.2lf\n", balance);



  return 0;
}
