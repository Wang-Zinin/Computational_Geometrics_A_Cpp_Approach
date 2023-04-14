
#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <string>

#include "../include/geoMath.h"

using namespace std;

int main(){
    Point p1 = {1.0,2.0};
    Point p2 = {3.0,1.0};
    p1.Cartesian_to_Polar();
    cout<<"P1 distance from the origin "<<p1.distance_from_origin()<<endl;
    cout<<"P1, P2 distance: "<<p1.distance_from_point(p2)<<endl;
    p1.print_Polar();
    cout<<endl;
}