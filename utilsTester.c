/*////////////////////////////////////////////////////////////////////////
//  Author: Li Linhan
//          Wendian Zhang
//          Jiahua Jia
//  Description: This is a driver program for
//          functions in utils.h, it provide
//          test cases for these functions.
//
//  Date: Sept.20 2018
/////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <math.h>
#define pi 3.14159265359

int main(int argc, char const *argv[]) {
//================degrees to radians===========================================================
  printf("=====================================================\n");
  printf("funciton testing: degreesToRadians\n");
  printf("=====================================================\n");

  double testCase_DegToRad[][2] = {
                                {180.0, pi  },//{degrees, radians}
                                {90.0 , pi/2},
                                {45.0 , pi/4}
                                  };

  int total = sizeof(testCase_DegToRad)/sizeof(testCase_DegToRad[0]);//get the # of test cases.
  int passed = 0;

  for (int i = 0; i < total; i++) {
    double functionOutput = degreesToRadians(testCase_DegToRad[i][0]); //save the function output for current test case

    if ( functionOutput == testCase_DegToRad[i][1]) {
        //test case passed
      printf("%lf \tdegree(s) = %lf \tradian(s)\tPassed\n", \
              testCase_DegToRad[i][0], testCase_DegToRad[i][1]);
      passed++;
    }else{
        //test case failed
      printf("%lf \tdegree(s) = %lf \tradian(s)\tbut the function output was %lf\n", \
              testCase_DegToRad[i][0], testCase_DegToRad[i][1], functionOutput);
    }
  }

  printf("total:%d\t\tpassed:%d\n", total, passed);
//====================air distance=================================================================
printf("=====================================================\n");
printf("function testing: getAirDistance\n");
printf("=====================================================\n");
/*            arg1    arg2    arg3    arg4    expected output
  test cases
      i       [0]     [1]     [2]     [3]       [4]
*/
  double testCase_AirDistance[][5] = {
                                    {41.9483,   -87.6556,   40.8206 ,  -96.7056,   764.990931},
                                    {40.8258,   -96.6852,   41.2524 ,  -95.9980,   74.645402},
                                    {48.8566,   2.3522,     -33.9249,  18.424100,  9341.738824},
                                    {-15.7942,  -47.8822,   55.7558,   -37.6173,   8014.116452}
                                  };
  total = sizeof(testCase_AirDistance)/sizeof(testCase_AirDistance[0]);//re-assign value for reuse
  passed = 0;                                                          //

  for (int i = 0; i < total; i++) {
    double functionOutput = getAirDistance( testCase_AirDistance[i][0],\
                                            testCase_AirDistance[i][1],\
                                            testCase_AirDistance[i][2],\
                                            testCase_AirDistance[i][3]);
    //round the Output to 6 decimal place to match the test cases
    functionOutput = round(functionOutput * pow(10.0, 6))/pow(10.0, 6);

    printf("origin:\t\t%lf\t%lf\n", \
            testCase_AirDistance[i][0], testCase_AirDistance[i][1]);
    printf("destination:\t%lf\t%lf\n", \
            testCase_AirDistance[i][2], testCase_AirDistance[i][3]);
    printf("distance = %lf, funciton output = %lf\t", \
            testCase_AirDistance[i][4], functionOutput);

    if (functionOutput == testCase_AirDistance[i][4]) {
      printf("PASSED\n");
      passed++;
    }else{
      printf("FAILED\n");
    }
  }
  printf("total:%d\t\tpassed:%d\n", total, passed);

//====================time dilation================================================================
printf("=====================================================\n");
printf("function testing: lorentzTimeDilation\n");
printf("=====================================================\n");
double testCase_timeDilation[][3] = {
                                      {1.0  ,0.25 , 1.032796},
                                      {12.0 ,0.70 , 16.803361},
                                      {166.0,0.99 , 1176.742800}
                                    };

total = sizeof(testCase_timeDilation)/sizeof(testCase_timeDilation[0]);
passed = 0;

for (int i = 0; i < total; i++) {
  double functionOutput = lorentzTimeDilation(  testCase_timeDilation[i][0],\
                                                testCase_timeDilation[i][1]);
  functionOutput = round(functionOutput * pow(10.0, 6))/pow(10.0, 6);


  printf("t = %lf\tc = %lf\n", testCase_timeDilation[i][0], testCase_timeDilation[i][1]);
  printf("Expected output: %lf\tFunction output: %lf\t", testCase_timeDilation[i][2], functionOutput);
  if (functionOutput == testCase_timeDilation[i][2]) {
    printf("PASSED\n");
    passed++;
  }else{
    printf("FAILED\n");
  }
}
printf("total:%d\t\tpassed:%d\n", total, passed);

  return 0;
}
