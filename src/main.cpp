
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <string>

#include "../include/geoMath.h"

using namespace std;

int main(){

    //test point 
    Point p1 = {3.0,2.0};
    Point p2 = {4.0,5.0};
    Point p3 = {5.0,8.0};
    p1.Cartesian_to_Polar();
    cout<<"P1 distance from the origin "<<p1.distance_from_origin()<<endl;
    cout<<"P1, P2 distance: "<<p1.distance_from_point(p2)<<endl;
    p1.print_Polar();
    cout<<"Is p1,p2,p3 collinear? "<<p1.collinear_points(p2,p3)<<endl;
    cout<<endl;

    //test line
    Line_ l1 ={p1,p2};
    l1.cal_slope_intercept();
    cout<<"l1 has slope of "<<l1.slope<<" and intercept of "<<l1.intercept<<endl;
    cout<<"Distance between l1 and origin is "<<l1.distance_from_origin()<<endl;
}