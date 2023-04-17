#ifndef GEOMATH_H
#define GEOMATH_H

#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

const double EPS_geo = 1E-5;

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

    
    bool collinear_points(Point p2, Point p3)
    {
        //if the slopes of l12 and l13 are the same and so does the intercepts of l12 and l13, then point p1,p2,p3 is collinear, otherwise not collinear
        double slope_12 = (y-p2.y)/(x-p2.x);
        double slope_23 = (p2.y-p3.y)/(p2.x-p3.x);

        double intercept_12 = (x*p2.y-p2.x*y)/(x-p2.x);
        double intercept_23 = (p2.x*p3.y-p3.x*p2.y)/(p2.x-p3.x);

        if(abs(slope_12-slope_23)<EPS_geo&&abs(intercept_12-intercept_23)<EPS_geo)
        {
            return 1;
        }
        else{
            return 0;
        }
    }


};
    
class Line_{
 public:
    Point d1,d2;
    double slope, intercept;

    void cal_slope_intercept(void){
        slope = (d1.y-d2.y)/(d1.x-d2.x);
        intercept = (d1.x*d2.y-d2.x*d1.y)/(d1.x-d2.x);
    }

    double distance_from_origin(void){
        return abs((d2.x-d1.x)*d1.y-(d2.y-d1.y)*d1.x)/sqrt((d2.x-d1.x)*(d2.x-d1.x)+(d2.y-d1.y)*(d2.y-d1.y));
    }

    int relationship_lines(Line_ l2) //=1, intersecting; =2, parallel; =3, identical
    {
        cal_slope_intercept();
        l2.cal_slope_intercept();
        if(abs(slope-l2.slope)<EPS_geo){
            if(abs(intercept-l2.intercept)<EPS_geo){
                return 3; //same slope and intercept, identical
            }
            else{
                return 2; //same slope, but different intercept, parallel
            }
        }
        else{
            return 1; //different slope and intercept, intersecting
        }
    }

    double distance_from_line(Line_ l2)
    {
        if(relationship_lines(l2)==2){
            return abs(intercept-l2.intercept)/sqrt(1+slope*slope);
        }
        else{
            return 0;
        }
    }

    double distance_from_point(Point p1){
        return abs((d2.x-d1.x)*(d1.y-p1.y)-(d1.x-p1.x)*(d2.y-d1.y))/(sqrt((d2.x-d1.x)*(d2.x-d1.x)+(d2.y-d1.y)*(d2.y-d1.y)));
    }

    
};


#endif