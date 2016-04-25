#include "Target.h"

#include <iostream>
#include <ctime>

using namespace std;

Target::Target()
	: tTime(0),height(0),width(0),tFound(false),sector("A-B-"){}


std::string Target::str()const{
	//This shit code :( 
	string s;
	s =  "Time: ";
    s += tTime;
    s += "\nHeight: ";
    s += height;
    s += "\nWidth: ";
    s += width;
	s += "\nFound: ";
    s += tFound;
    //s += "\nPlane Position: ";
    //s += sector;
    s += "\n";
	return s;
}

