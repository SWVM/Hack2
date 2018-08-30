/************************************************************
// NAME:LIN LINHAN
//      
//      
// DESCRIPTION: this program promote user for cordination of two point on earth and calculate the distance between them
//
//
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DegToRad (3.14159265359/180)
#define Radius_Earth 6371.00
int main(int argc, char const *argv[]) {
  double lati_origin = 0;
  double longi_origin = 0;
  double lati_destination = 0;
  double longi_destination = 0;
  //variables to store the original input for the output
  double input_1, input_2, input_3, input_4;

  printf("Please enter the latitude of the origin\n");
  scanf("%lf", &lati_origin);
  input_1 = lati_origin;
  lati_origin = lati_origin * DegToRad;

  printf("Please enter the longitude of the origin\n");
  scanf("%lf", &longi_origin);
  input_2 = longi_origin;
  longi_origin = longi_origin * DegToRad;

  printf("Please enter the latitude of the destination\n");
  scanf("%lf", &lati_destination);
  input_3 = lati_destination;
  lati_destination = lati_destination * DegToRad;

  printf("Please enter the longitude of the destination\n");
  scanf("%lf", &longi_destination);
  input_4 = longi_destination;
  longi_destination = longi_destination * DegToRad;

  //put the formula into multi-steps calculation for a better veiw
  double delta = longi_origin - longi_destination;
  double inner = sin(lati_origin)*sin(lati_destination)+cos(lati_origin)*cos(lati_destination)*cos(delta);
  double distance = acos(inner)*Radius_Earth;
  //DEBBUGING OUTPUTS
  // printf("%lf\n", delta);
  // printf("%lf\n", distance);
  // printf("%lf\n", Radius_Earth);
  // printf("%lf\n", sin(lati_origin)*sin(longi_origin)+cos(lati_destination*cos(longi_destination)*delta));

  printf("Location Distance\n");
  printf("========================\n");
  printf("Origin:\t\t(%f, %f)\n", input_1, input_2);
  printf("Destination:\t(%f, %f)\n", input_3, input_4);
  printf("Air distance is %lf kms\n", distance);

    return 0;
}
