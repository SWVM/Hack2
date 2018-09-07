/*////////////////////////////////////////////////////////////////////////
//  Author: Li Linhan
//
//
//  Date:2018 Sept.6
//  Description: this program reads in inputs from command line
//              and inform the user about their data usage.
//  Inputs(respectively): • Number of GB in the plan per 30 day period
//                        • The current day in the 30 day period
//                        • The total number of GB used so far
//
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

  if (argc != 4) {
    printf("check your arguments and try again\n");
    return 1;
  }


//  getting input from command line
  double DataPerM = atof(argv[1]);
  int Date = atoi(argv[2]);
  double DataUsed = atof(argv[3]);

//  check for valid input
  if (Date > 30 || DataUsed < 0 || DataPerM <0) {
    printf("ERROR: invalid input\n");
    return 1;
  }

//  declaring variables
  double Current_Daily_Avg = DataUsed / Date;
  double Ideally_Daily_Avg = DataPerM / 30;
  double Data_Remaining = DataPerM - DataUsed;
  int Days_Remaining = 30 - Date;
  double Exceed = Current_Daily_Avg * 30 - DataPerM;
  double Rate_To_Stay_Below = Data_Remaining / Days_Remaining;

//  Output
  printf("%d days used, %d days remaining\n", Date, Days_Remaining);
  printf("Average daily use: %.2lf  GB/day\n", Current_Daily_Avg);
  printf("\n");

  //  if no data remaining, print the exceeded amount.
  if (Data_Remaining <= 0) {
    printf("You have used all of your data for this month!\n");
    printf("data used outside the plan: %.2lfGB\n", fabs(Data_Remaining));

  }
  // if have data remaining, print the rate at which the data plan could be used without exceeding.
  else {
    //if the user used more than the average value, a predicted exceeded amount will be given.
    if (Current_Daily_Avg > Ideally_Daily_Avg) {
      printf("You are EXCEEDING your average daily use (%.2lf GB/day)\n", Ideally_Daily_Avg);
      printf("Continuing this high usage, you'll exceed your data plan by %.2lf  GB.\n", Exceed);
      printf("To stay below your data plan, use no more than %.2lf GB/day.\n", Rate_To_Stay_Below);
    }
    else {
      printf("You are at or below your average daily used (%.2lf GB/day)\n", Ideally_Daily_Avg);
      printf("You can use as much as %.2lf GB per day\n", Rate_To_Stay_Below);
    }
  }


  return 0;
}
