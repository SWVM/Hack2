/*//////////////////////////////////////////////
 * AUTHOR = LI LINHAN
 *          ZHANG WENDIAN
 *          JIA JIAHUA
 * DESCRIPTION: this is a source file for string_utils.h
 *          for CSCE 155E HACK8.0
 *
 * DATE: Oct.12, 2018
 //////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "string_utils.h"

void replaceChar(char *s, char oldChar, char newChar){
  size_t length = strlen(s);
  for (size_t i = 0; i < length; i++) {
    if (s[i] == oldChar) {
      s[i] = newChar;
    }
  }
  return;
}

char * replaceCharCopy(const char *s, char oldChar, char newChar){
  char* newStr = makeCopy(s);
  replaceChar(newStr, oldChar, newChar);

  return newStr;
}

void removeChar(char *s, char c){
  size_t length = strlen(s)+1;
  //go through the given string
  for (size_t i = 0; i < length; i++) {
    //find the char to remove
    if (s[i] == c) {
      //swap it with the next char to keep(including '\0')
      for (size_t j = i; j < length; j++) {
        if (s[j] != c) {
          s[i] = s[j];
          s[j] = c;
          break;
        }
      }
    }
  }
  return;

}

char * removeCharCopy(const char *s, char c){
  char* newStr = makeCopy(s);
  removeChar(newStr, c);

  return newStr;
}

char **lengthSplit(const char *s, int n){
  int length = strlen(s);
  int rows = (int)(ceil((double)length/n));
  char** newArr = (char**)malloc(rows*sizeof(char*));

  for (size_t i = 0; i < rows; i++) {
    newArr[i] = (char*)malloc((n+1) * sizeof(char));
  }
  //index == current position on the given string, s
  size_t index = 0;
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < n; j++) {
      newArr[i][j] = s[index];
      index++;
    }
    //add a \0 to the end of each substring
    newArr[i][n] = '\0';
  }

  return newArr;
}
// helper function
char * makeCopy(const char *s){
  int length = strlen(s)+1;
  char* new = (char*)malloc(length*sizeof(char));
  for (size_t i = 0; i < length; i++) {
    new[i] = s[i];
  }

  return new;
}
