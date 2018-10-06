/*//////////////////////////////////////////////
 * AUTHOR = LI LINHAN
 *          ZHANG WENDIAN
 *          JIA JIAHUA
 *FUNCTIONS:
 *        copyImage()
 *        flipHorizontal()
 *        flipVertical()
 *        rotateClockwise()
 *
 * DESCRIPTION: this is a source file for imageUtils.h
 *          for CSCE 155E HACK7.0
 *
 * DATE: Oct.5, 2018
 //////////////////////////////////////////////*/


#include <stdlib.h>
#include <stdio.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "imageUtils.h"

Pixel **loadImage(const char *filePath, int *height, int *width) {
  int x,y,n;
  unsigned char *data = stbi_load(filePath, &x, &y, &n, 4); //4 = force RGBA channels
  *height = y;
  *width = x;

  //contiguous allocation:
  Pixel **image = (Pixel **)malloc(sizeof(Pixel *) * y);
  image[0] = (Pixel *)malloc(sizeof(Pixel) * (y * x));
  for(int i=1; i<y; i++) {
    image[i] = (*image + (x * i));
  }

  int rowIndex = 0;
  int colIndex = 0;
  for(int i=0; i<(x * y * 4); i+=4) { //for each row
      image[rowIndex][colIndex].red   = data[i+0];
      image[rowIndex][colIndex].green = data[i+1];
      image[rowIndex][colIndex].blue  = data[i+2];
      colIndex++;
      if(colIndex == x) {
        //go to next row, reset column
        rowIndex++;
        colIndex=0;
      }
  }
  stbi_image_free(data);
  return image;
}

void saveImage(const char *fileName, Pixel **image, int height, int width) {

  // Convert height x width Pixel array to single array with
  // 3 (RGB) channels, ignoring the alpha channel and assume 100% opaque
  unsigned char *data = (unsigned char *) malloc(height * width * 3);
  int x = 0;
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      data[x+0] = image[i][j].red;
      data[x+1] = image[i][j].green;
      data[x+2] = image[i][j].blue;
      x+=3;
    }
  }
  //write
  stbi_write_jpg(fileName, width, height, 3, data, 100);
  free(data);
  return;
}

Pixel ** copyImage(Pixel **image, int height, int width) {

  Pixel **copy = (Pixel**)malloc(sizeof(Pixel*)*height);
  copy[0] = (Pixel*)malloc(sizeof(Pixel)*height*width);
  for (int i = 0; i < height; i++) {
    copy[i] = copy[0] + width*i;
  }

  for (int col = 0; col < height; col++) {
    for (int row = 0; row < width; row++) {
      copy[col][row] = image[col][row];
    }
  }

  return copy;
}

void flipHorizontal(Pixel **image, int height, int width) {
  Pixel temp;

  for (int col = 0; col < height; col++) {
    for (int row = 0; row < (width/2); row++) {
      temp = image[col][row];
      image[col][row] = image[col][width-(1+row)];
      image[col][width-1-row] = temp;
    }
  }

  return;
}

void flipVertical(Pixel **image, int height, int width) {
  Pixel *temp;

  for (int i = 0; i < (height/2); i++) {
    temp = image[i];
    image[i] = image[height-(1+i)];
    image[height-(1+i)] = temp;
  }

  return;
}

Pixel ** rotateClockwise(Pixel **image, int height, int width) {
  Pixel **copy = (Pixel**)malloc(sizeof(Pixel*)*width);
  copy[0] = (Pixel*)malloc(sizeof(Pixel)*height*width);
  for (int i = 0; i < width; i++) {
    copy[i] = copy[0]+(height*i);
  }

  for (int col = 0; col < height; col++) {
    //change the rows to columns, and columns to rows
    for (int row = 0; row < width; row++) {
      copy[row][height-(col+1)] = image[col][row];
        //printf("copying row%d, col%d\n", col,row);
    }
  }

  return copy;
}



//  These are just for fun

// void removeDark(Pixel **image, int height, int width, int thresh){
//   for (int i = 0; i < height; i++) {
//     for (int j = 0; j < width; j++) {
//       if ((i%5 == 0)||(j%5 == 0)) {
//         goBlack(&image[i][j]);
//       }
//
//     }
//   }
//   return;
// }
//
// int getGrayScale(Pixel a){
//   int sum = a.red + a.green + a.blue;
//
//   return sum/3;
// }
//
// void goBlack(Pixel* a){
//   (*a).red = 0;
//   (*a).green = 0;
//   (*a).blue = 0;
//   return;
// }
