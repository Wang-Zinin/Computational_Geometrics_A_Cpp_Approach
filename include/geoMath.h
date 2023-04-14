#ifndef GEOMATH_H
#define GEOMATH_H

#include <math.h>
#include <vector>

using namespace std;

//list of class
class Point;


class Point{
 public:
    double x,y;
    
    double distance_from_origin(void){
        return sqrt(x*x+y*y);
    }
};



#endif