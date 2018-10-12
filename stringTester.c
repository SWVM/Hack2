/*//////////////////////////////////////////////
 * AUTHOR = LI LINHAN
 *          ZHANG WENDIAN
 *          JIA JIAHUA
 * DESCRIPTION: this is a driver file for string_utils.c
 *          for CSCE 155E HACK8.0
 *
 * DATE: Oct.12, 2018
 //////////////////////////////////////////////*/

struct testCase{
  char* input;
  char arg_1;
  char arg_2;
  char* output;
};
struct split{
  char* input;
  int arg_1;
  int num_substring;
  char* output[20];
};
void print_2D(char** s, int index);
void print_details(char* input, char** expect, char** output, int len, int n);




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

int main(int argc, char const *argv[]) {
  int passed, num;
  char* temp;

  printf("=========Testing: replaceChar=========================================\n");
  struct testCase cases_1[] = {
      {"fassafsfafsaasfff"  ,'a'  ,'b'  ,"fbssbfsfbfsbbsfff"},
      {"ddddddddddddd"      ,'d'  ,'s'  ,"sssssssssssss"},
      {"owepqirwpqrjw"      ,'1'  ,'o'  ,"owepqirwpqrjw"}};
  num = sizeof(cases_1)/sizeof(cases_1[1]);
  passed = 0;

  for (size_t i = 0; i < num; i++) {
    temp = (char*)malloc(sizeof(cases_1[i].input));
    strcpy(temp, cases_1[i].input);

    replaceChar(temp, cases_1[i].arg_1, cases_1[i].arg_2);

    printf("input\t%s\toldChar = %c\n"  ,cases_1[i].input,  cases_1[i].arg_1);
    printf("output\t%s\tnewChar = %c\t" ,temp      ,  cases_1[i].arg_2);
    if ( !(strcmp( temp, cases_1[i].output )) ) {
      passed++;
      printf("PASSED\n");
    }else{
      printf("FAILED\n");
    }

    free(temp);
    temp = NULL;
  }

  printf("total:%d, passed:%d\n", num, passed);

  printf("\n=========Testing: replaceCharCopy=====================================\n");
  struct testCase cases_2[] = {
      {"fassafsfafsaasfff"  ,'a'  ,'b'  ,"fbssbfsfbfsbbsfff"},
      {"ddddddddddddd"      ,'d'  ,'s'  ,"sssssssssssss"},
      {"owepqirwpqrjw"      ,'1'  ,'o'  ,"owepqirwpqrjw"}};
  num = sizeof(cases_2)/sizeof(cases_2[1]);
  passed = 0;

  for (size_t i = 0; i < num; i++) {
    temp = replaceCharCopy(cases_2[i].input, cases_2[i].arg_1, cases_2[i].arg_2);

    printf("input\t%s\toldChar = %c\n"  ,cases_2[i].input,  cases_2[i].arg_1);
    printf("output\t%s\tnewChar = %c\t" ,temp      ,  cases_2[i].arg_2);
    if ( !(strcmp( temp, cases_2[i].output )) ) {
      passed++;
      printf("PASSED\n");
    }else{
      printf("FAILED\n");
    }

    free(temp);
    temp = NULL;
  }

  printf("total:%d, passed:%d\n", num, passed);

  printf("\n=========Testing: removeChar==========================================\n");
  struct testCase cases_3[] = {
      {"fassafsfafsaasfff"  ,'a'  ,'0'  ,"fssfsffssfff"},
      {"ddddddddddddd"      ,'d'  ,'0'  ,"\0"},
      {"owepqirwpqrjw"      ,'1'  ,'0'  ,"owepqirwpqrjw"}};
  num = sizeof(cases_3)/sizeof(cases_3[1]);
  passed = 0;

  for (size_t i = 0; i < num; i++) {
    temp = (char*)malloc(sizeof(cases_3[i].input));
    strcpy(temp, cases_3[i].input);

    removeChar(temp, cases_3[i].arg_1);

    printf("input\t%s\tremove = %c\n"  ,cases_3[i].input,  cases_3[i].arg_1);
    printf("output\t%s\t"              ,temp);
    if ( !(strcmp( temp, cases_3[i].output )) ) {
      passed++;
      printf("PASSED\n");
    }else{
      printf("FAILED\n");
    }

    free(temp);
    temp = NULL;
  }

  printf("total:%d, passed:%d\n", num, passed);


  printf("\n=========Testing: removeCharCopy======================================\n");
  struct testCase cases_4[] = {
      {"fassafsfafsaasfff"  ,'a'  ,'0'  ,"fssfsffssfff"},
      {"ddddddddddddd"      ,'d'  ,'0'  ,"\0"},
      {"owepqirwpqrjw"      ,'1'  ,'0'  ,"owepqirwpqrjw"}};
  num = sizeof(cases_4)/sizeof(cases_4[1]);
  passed = 0;

  for (size_t i = 0; i < num; i++) {
    temp = removeCharCopy(cases_4[i].input, cases_4[i].arg_1);

    printf("input\t%s\tremove = %c\n"  ,cases_4[i].input,  cases_4[i].arg_1);
    printf("output\t%s\t"              ,temp);
    if ( !(strcmp( temp, cases_4[i].output )) ) {
      passed++;
      printf("PASSED\n");
    }else{
      printf("FAILED\n");
    }

    free(temp);
    temp = NULL;
  }
  printf("total:%d, passed:%d\n", num, passed);

  printf("\n=========Testing: lengthSplit=========================================\n");
  struct split case_5[] = {
    {"abcdefghijklmn", 3, 5   ,{"abc\0","def\0","ghi\0","jkl\0","mn\0"}},
    {"1234567890",     5, 2   ,{"12345\0","67890\0"}},
    {"qwepoi123",      1, 9   ,{"q\0","w\0","e\0","p\0","o\0","i\0","1\0","2\0","3\0"}}};
  num = sizeof(case_5)/sizeof(case_5[0]);
  passed = 0;
  char** temp_5;
  int fail;
  // go through each test case
  for (size_t i = 0; i < num; i++) {
    fail = 0;
    temp_5 = lengthSplit(case_5[i].input, case_5[i].arg_1);
    /*compare the substrings produced by the function with the expected output
     *  mark the test case as filed and break the loop if one of them does not match
     */
    for (size_t j = 0; j < case_5[i].num_substring; j++) {
      if (strcmp(temp_5[j], case_5[i].output[j])) {
        fail = 1;
        break;
      }
    }

    print_details(case_5[i].input, case_5[i].output, temp_5, case_5[i].num_substring, case_5[i].arg_1);
    if (fail) {
      printf("failed\n");
    }else{
      printf("passed\n");
      passed++;
    }

    free(temp);
    temp = NULL;
  }
  printf("total:%d, passed:%d\n", num, passed);

  return 0;
}

/* Customised functions to inprove readability
 *
 *
*/
void print_details(char* input, char** expect, char** output, int len, int n){
  printf("Input was:\t%s\t%d\n", input, n);
  printf("Expecting:\t");
  print_2D(expect, len);
  printf("\nOutput:\t\t");
  print_2D(output, len);
  printf("\n");
  return;
}


void print_2D(char** s, int index){
  for (size_t i = 0; i < index; i++) {
    printf("%s\t", s[i]);
  }
  return;
}
