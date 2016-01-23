#ifndef ISRHEADER_H
#define ISRHEADER_H

#include <iostream>
#include <stdio.h>
//                         This is for windows to find includes ///////////////////
//#include "stdafx.h"
//#include <iostream>
//#include <stdio.h>
//#include <opencv2\opencv.hpp>
//#include "opencv2\highgui\highgui.hpp"
//#include "opencv2\imgproc\imgproc.hpp"
//#include "opencv2\core\core.hpp"
//#include "opencv2\features2d\features2d.hpp"
//#include "opencv2\nonfree\nonfree.hpp"
//#include "opencv2\calib3d\calib3d.hpp"
//#include <opencv2\video\background_segm.hpp>


// These are Mac includes comment these out and uncomment the windows includes////////

#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/features2d.hpp" // mac version of nonfree.hpp
//#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include <opencv2/video/background_segm.hpp>

#include <cmath>

#include "isrheader.h"

using namespace cv;
using namespace std;

void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);


void contour(Mat& imgThresholded, Mat& imgOriginal, Mat& img);


#endif