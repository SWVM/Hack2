/*//////////////////////////////////////////////
 * AUTHOR = LI LINHAN
 *          ZHANG WENDIAN
 *          JIA JIAHUA
 * DESCRIPTION: this is a header file for string_utils.c
 *          for CSCE 155E HACK8.0
 *
 * DATE: Oct.12, 2018
 //////////////////////////////////////////////*/



/*///////////////////////////////////////////
 *  replace the oldchar in the given string
 *  with newChar
 */
void replaceChar(char *s, char oldChar, char newChar);

/*///////////////////////////////////////////
 *  return the pointer to the copy of the given
 *  string, s, with old char replaced by newchar
 */
char * replaceCharCopy(const char *s, char oldChar, char newChar);

/*///////////////////////////////////////////
 *  remove char c from the string s, and
 *   shift down the characters to fill the blanks
*/
void removeChar(char *s, char c);

/*///////////////////////////////////////////
 *  return the pointer to the copy of the given
 *  string, with char c removed
 */
char * removeCharCopy(const char *s, char c);

/*///////////////////////////////////////////
 *  cut the given string into substrings of
 *  given lenght, store them in to a 2D array
 *  and returns a pointer to it.
 */
char **lengthSplit(const char *s, int n);

/*///////////////////////////////////////////
 *  make a copy of the given string.
 *  returns a pointer to it
 */
char * makeCopy(const char *s);
