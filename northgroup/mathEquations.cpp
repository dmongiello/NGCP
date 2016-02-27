//  Copyright © 2016 David Mongiello. All rights reserved.
//
#include <iomanip>
#include <iostream>
#include <sys/utime.h>
#include "main.hpp"
#include HoughCircle.cpp
using namespace std;

// Had to edit preprocessor definitions to get timeStamp to work (Error C4996). properties> config>prop. > C/C++> preprocessor> prepross. def.> Edit
// Type in "_CRT_SECURE_NO_WARNINGS" and save  - Michael Perez

void angleRad(Mat imgThresholded){

	double widX = imgThresholded.cols;//takes width of img
	double lenY = imgThresholded.rows;//takes length of img
	double x = widX / 2;
	double y = lenY / 2;

	double arrayCen[2] = { (x, y };//center of image
	double diff[2] = { x - cenX, y - cenY };//find distance from center image to center circ(not sure what the var for cent
											//is used a filler
	

	
	double rad = sqrt(diff[0]*diff[0] + diff[1]*diff[1]);
	double angle = atan2(diff[0] / diff[1]);
	time_t ltime; /* calendar time */
	ltime = time(NULL); /* get current cal time */
	printf("%s", asctime(localtime(&ltime)));
	


} 
