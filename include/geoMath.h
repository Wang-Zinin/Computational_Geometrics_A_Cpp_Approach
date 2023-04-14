#ifndef GEOMATH_H
#define GEOMATH_H

#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

//list of class
class Point;
class Line_;

class Point{
 public:
    double x,y; //Cartesian coordinates
    double r,t; //Polar coordinates
    
    double distance_from_origin(void)
    {
        return sqrt(x*x+y*y);
    }
    
    void print_Cartesian(void)
    {
        cout<<"Point position: ("<<x<<","<<y<<")."<<endl;
    }

    void print_Polar(void)
    {
        cout<<"Point position (Polar coordinates): ("<<r<<","<<t<<")."<<endl;
    }
    
    void Cartesian_to_Polar(void)
    {
        r=distance_from_origin();
        t=atan(y/x);
    }

    double distance_from_point(Point p2)
    {
        return sqrt((x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y));
    }

    bool collinear_points(Point p2, Point p3);

};

class Line_{
 public:
    Point d1,d2;
    double slope, intercept;

    void cal_slope_intercept(void);
    double distance_from_origin(void);
    int relationship_lines(Line_ l2); //=1, intersecting; =2, paralell; =3, identical
    double distance_from_line(Line_ l2);
    double distance_from_point(Point p1); 
};


#endif