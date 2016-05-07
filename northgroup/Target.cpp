#include "Target.h"

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

Target::Target()
:tLongitude(0.0),tLatitude(0.0){}





//MAVLINK HERE "PARSE THE SECONDS OF THE LONGITUDE AND LATITUDE"
double Target::getGPSlatitude(){
    return 0.0;
}
double Target::getGPSlongitude(){
    return 0.0;
}
//Degrees of North, could be called Header
double Target::getTheta(){
    return 0.0;
}

void Target::mathEquations(double x, double y){
    
    double xdistance = 0.0;
    double ydistance = 0.0;
    
    double xresolution = 0;
    double yresolution = 0;
    
    double targetxlocation = x;
    double targetylocation = y;
    
    double radiusR = 0.0;
    double theta = getTheta();
    
    bool inQuadrant1 = 0 < theta && theta <= 90;
    bool inQuadrant2 = 90 < theta && theta <=180;
    bool inQuadrant3 = 180 < theta && theta <=270;
    
    //find location of xpixel relative to the center
    xdistance = ((targetxlocation-xresolution/2)-xresolution/2);
    //find location of ypixel relative to the center
    ydistance = ((targetylocation-yresolution/2)-yresolution/2);
    
    
    radiusR = pow((pow(xdistance,2)+ pow(ydistance,2)),(1/2));
    
    double rlongitude = 0.0;
    double rlatitude = 0.0;
    
    if(inQuadrant1){
        rlongitude = radiusR * sin(theta);//positive value
        rlatitude = radiusR * cos(theta);//positive value
    }else if(inQuadrant2){
        rlongitude = radiusR * sin(theta - 90);//negative value
        rlatitude = radiusR * cos(theta - 90);//positive value
   
    }else if(inQuadrant3){
        rlongitude = radiusR * sin(theta - 180);//negative value
        rlatitude = radiusR * cos(theta - 180);//positive value
   
    }else{
        rlongitude = radiusR * sin(theta - 270);//negative value
        rlatitude = radiusR * cos(theta - 270);//positive value
    }
    
    double rlongPrime = (rlongitude*0.000198962) + getGPSlongitude();
    double rlatPrime = (rlatitude*0.000198962) + getGPSlatitude();
    
    
    setLongitude(rlongPrime);
    setLatititude(rlatPrime);
    
    
} 





