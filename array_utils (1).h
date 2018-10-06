/*//////////////////////////////////////////////
 * AUTHOR = LI LINHAN
 *          ZHANG WENDIAN
 *          JIA JIAHUA
 * DESCRIPTION: this is a header file for array_utils.c
 *          for CSCE 155E HACK7.0
 *
 * DATE: Oct.5, 2018
 //////////////////////////////////////////////*/


/*search for x in the given array
 * returns 1 if x is fund in the array
 * returns 0 if not*/
int contains(const int *arr, int size, int x);
/*search for x between index i and j of the given array
* returns 1 if x is fund in the array
* returns 0 if not*/
int containsWithin(const int *arr, int size, int x, int i, int j);
/* returns a pinter to the copy of the given array,
 * any exceeded elements in the given array will
 * be dropped and any spaces in the new array
 * will be filled with a zero.*/
int * paddedCopy(const int *arr, int oldSize, int newSize);
/* reverses the given array, mek changes directely to the array_utils
*/
void reverse(int *arr, int size);
/* returns a pointer to the reversed copy of the given array*/
int * reverseCopy(const int *arr, int size);
