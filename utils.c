/*////////////////////////////////////////////////////////////////////////
//  Author: Li Linhan
//          Wendian Zhang
//          Jiahua Jia
//  Description: This is a libarary for CSCE 155E
//          HACK5.
//          INCLUDE IT WITH "utils.h"
//
//  Contains: degreesToRadians
//            getAirDistance
              lorentzTimeDilation
//
//  Date: Sept.19 2018
/////////////////////////////////////////////*/

#include <math.h>
#include "utils.h"
#define c 299792458.0

/*//////////////////////////////////////////////////////
//  Function: DegreesToRadians
//  Description: takes value of an angle in degrees(double),
//            and return its value in radians(double).
//////////////////////////////////////////////////////*/
double degreesToRadians(double degree){

    return degree * (3.14159265359/180);

}

/*/////////////////////////////////////////////////////
//  Function: getAirDistance
//  Description: takes the cordination of two point,
//                returns the air distance between them.
/////////////////////////////////////////////////////*/
double getAirDistance(double originLatitude,
                      double originLongitude,
                      double destinationLatitude,
                      double destinationLongitude){
    originLatitude = degreesToRadians(originLatitude);
    originLongitude = degreesToRadians(originLongitude);
    destinationLatitude = degreesToRadians(destinationLatitude);
    destinationLongitude = degreesToRadians(destinationLongitude);

    double delta = originLongitude - destinationLongitude;
    double inner = sin(originLatitude) * sin(destinationLatitude) \
                    +cos(originLatitude) * cos(destinationLatitude) * cos(delta);
    double distance = acos(inner) * 6371.00;
    return distance;
}

/*//////////////////////////////////////////////////////
//  Function: lorentzTimeDilation
//  Description: takes the duration and the speed(in percent of C)
//                of the travel, returns the dilated time
//                 experienced by the raveler.
//////////////////////////////////////////////////////*/
double lorentzTimeDilation(double t, double percentC){
    return t/sqrt(1.0 - (pow(percentC*c,2.0)/pow(c, 2.0)));
}
