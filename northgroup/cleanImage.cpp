//
//  cleanImage.cpp
//  northgroup
//
//  Created by David Mongiello on 2/14/16.
//  Copyright © 2016 David Mongiello. All rights reserved.
//

#include "main.hpp"
using namespace cv;
using namespace std;
void cleanImage(Mat& imgThresholded)
{
//morphological opening (remove small objects from the foreground)
erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
//morphological closing (fill small holes in the foreground)
dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
}