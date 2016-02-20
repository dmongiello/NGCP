//  Copyright © 2016 David Mongiello. All rights reserved.
//
#include <iomanip>
#include <iostream>
#include <sys/utime.h>
#include "main.hpp"
#include HoughCircle.cpp
using namespace std;


void angleRad(Mat imgThresholded){

	double widX = imgThresholded.cols;//takes width of img
	double lenY = imgThresholded.rows;//takes length of img
	double x = widX / 2;
	double y = lenY / 2;

	double arrayCen[2] = { (x, y };//center of image
	double diff[2] = { x - cenX, y - cenY };//find distance from center image to center circ(not sure what the var for cent
											//is used a filler
	

	
	double rad = sqrt(diff[0]*diff[0] + diff[1]*diff[1]);
	double angle = atan(diff[0] / diff[1]);
	cout << time(0) << endl;
	


} 
