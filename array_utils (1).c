/*//////////////////////////////////////////////
 * AUTHOR = LI LINHAN
 *          ZHANG WENDIAN
 *          JIA JIAHUA
 *
 * DESCRIPTION: this is a source file for array_utils.h
 *          for CSCE 155E HACK7.0
 *
 * DATE: Oct.5, 2018
 //////////////////////////////////////////////*/


#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"

int contains(const int *arr, int size, int x){
  for (int i = 0; i < size; i++) {
    if (arr[i] == x) {
      return 1;
    }
  }

  return 0;
}

int containsWithin(const int *arr, int size, int x, int i, int j){
  for ( ; i < j+1; i++) {
    if (arr[i] == x) {
      return 1;
    }
  }

  return 0;
}

int  * paddedCopy(const int *arr, int oldSize, int newSize){
  int *newArr = (int*)malloc(sizeof(int) * newSize);
  int i;
  /*assign value to the new array until the index reaches the
   * smaller one of the two size*/
  for ( i = 0; i < ((oldSize>newSize)?newSize:oldSize); i++) {
    newArr[i] = arr[i];
  }
  /*if the newSize is smaller, then it's over
   *if not, assign zeros until the index reaches the newSize*/
  if (oldSize < newSize) {
    for ( ; i < newSize; i++) {
      newArr[i] = 0;
    }
  }

  return newArr;
}

void reverse(int *arr, int size){
  int temp;

  for (int i = 0; i < size/2; i++) {
    temp = arr[i];
    arr[i] = arr[size-(1+i)];
    arr[size-(1+i)] = temp;
  }

  return;
}

int * reverseCopy(const int *arr, int size){
  int *newArr = (int*)malloc(size*sizeof(int));

  for (int i = 0; i < size; i++) {
    newArr[i] = arr[size-(1+i)];
  }

  return newArr;
}
