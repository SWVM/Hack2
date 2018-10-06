/*//////////////////////////////////////////////
 * AUTHOR = LI LINHAN
 *          ZHANG WENDIAN
 *          JIA JIAHUA
 * FUNCTIONS:
 *        copyImage()
 *        flipHorizontal()
 *        flipVertical()
 *        rotateClockwise()
 *
 * DESCRIPTION: this is a header file for imageUtils.c
 *          for CSCE 155E HACK7.0
 *
 * DATE: Oct.5, 2018
 //////////////////////////////////////////////*/


/**
 * A structure that represents a single pixel value using
 * the RGB (red-blue-green) color model.  Each integer
 * value is in the range [0, 255].
 */
typedef struct {
  int red;
  int green;
  int blue;
} Pixel;

/**
 * Loads an image file specified by the given file path/name.
 * The height and width are indicated in the two pass-by-reference variables.
 * The image is returned as a two-dimensional array of Pixel values
 * of dimension (height x width) where the pixel at [0][0] corresponds to
 * the top-left most pixel value.
 */
Pixel **loadImage(const char *filePath, int *height, int *width);

/**
 * Saves the given image (which is assumed to have the same format as in
 * loadImage() and is of the given height x width) to the file specified
 * by the given path/name.
 */
void saveImage(const char *filePath, Pixel **image, int height, int width);

/**
 * Make a deepcopy of the given image, returns the pointer
 * to the deepcopy if seccessful.
 */
Pixel ** copyImage(Pixel **image, int height, int width);

/**
 * Flip the given image horizontally by switching Pixels in each row,
 *  modify the loaded image passed by reference directly.
 */
void flipHorizontal(Pixel **image, int height, int width);

/**
 * Flip the given image vertically by switching pointers to
 * the rows
 *  modify the loaded image passed by reference directly.
 */
void flipVertical(Pixel **image, int height, int width);

/**
 * Rotate the given image by exchanging its rows and columns,
 * save it as a copy and return the
 * pointer to the rotated image.
 * NOTE: the height and the width are exchanged for the rotated copy
 */
Pixel ** rotateClockwise(Pixel **image, int height, int width);


//These are just functions I made for fun
// void removeDark(Pixel **image, int height, int width, int thresh);
// void goBlack(Pixel* a);
// int getGrayScale(Pixel a);
