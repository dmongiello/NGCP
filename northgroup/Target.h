#ifndef TARGET_H
#define TARGET_H
#include <iostream>
#include <string>

class Target {
private:
    //THESE ARE IN SECONDS, as in Degrees.minutes.Seconds.
    double tLongitude;
    double tLatitude;
public:
	//constructor
    Target();
    
    //GET MAVLINK INFO
    double getTheta();
    //Value in seconds
    double getGPSlongitude();
    double getGPSlatitude();
    
	//getters
    double getLongitude() const { return tLongitude;}
    double getLatitude() const { return tLatitude;}
   
    
    /* --- MAVLINK --- */
    //setters for the seconds of the gps coordinate of the targert, in seconds.
    void setLongitude(double n){ tLongitude = n;}
    void setLatititude (double n) { tLatitude = n;}
    
    //Helper Functions
    void mathEquations(double x, double  y);
};
#endif