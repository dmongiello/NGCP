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

//void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);

void contour(Mat& imgThresholded, Mat& imgOriginal, Mat& img)
{
	Mat bw;
	Canny(imgThresholded, bw, 0, 50, 5); //Edge Detector 
	vector<vector<Point>> contours;

	findContours(bw, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	/// Approximate contours to polygons + get bounding rects and circles
	vector<vector<Point>> contours_draw(contours.size());
	vector<Point>contours_poly;

	for (int i = 0; i < contours.size(); i++) //set labels or identify shapes in this loop
	{
		double area = contourArea(contours[i]);
		Rect r = boundingRect(contours[i]);
		int radius = r.width / 2;//simple way of finding radius. this should be updated to be more complex

		if (abs - ((double)r.width / r.height)) <= 0.2 && abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2 && area > 200) //area the countour has to fit the theoretical area of a circle
		{(
			setLabel(imgOriginal, "CIR", contours[i]); //give stick cir on it to indentify it
			Mat drawing = Mat::zeros(imgThresholded.size(), CV_8UC3);
			for (int i = 0; i< contours.size(); i++)
			{
				Scalar color = Scalar(0, 0, 0);
				drawContours(imgOriginal, contours_draw, i, color, 5, 8, vector<Vec4i>(), 0, Point());	//Draw around the found target
				drawContours(img, contours_draw, i, color, 5, 8, vector<Vec4i>(), 0, Point());
				
			}
		}
	}
}
