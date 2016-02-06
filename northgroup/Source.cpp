#include <iostream>
#include <stdio.h>
#include < opencv2\opencv.hpp>  
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include < opencv2/video/background_segm.hpp> 
#include <cmath>
#include "isrheader.h"

using namespace cv;
using namespace std;



//void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);


//void contour(Mat& imgThresholded, Mat& imgOriginal, Mat& img);



int main(int argc, char** argv)
{

	VideoCapture cap(0); //capture the video from web cam,0 means default

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	//Set the color value for Hue, Saturation, Brightness/Value.
	int iLowH = 0;
	int iHighH = 50;
	iLowH = iLowH / 2;
	iHighH = iHighH / 2;

	int iLowS = 50;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;
	Mat imgOriginal;

	while (true)
	{
		Mat img;

		bool bSuccess = cap.read(imgOriginal); // read a new frame from video
		img = imgOriginal.clone();
		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		int width = img.size().width;
		int height = img.size().height;
		Mat black = Mat::zeros(height, width, CV_8UC3); //Empty Image of Zeros
		threshold(img, img, 100, 255, 0); //Change Value to Max or Min based on threshold Value
		Mat imgHSV;


		cvtColor(img, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat imgThresholded; 

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image For Hue using Upper and Lower Ranges

		//morphological opening (remove small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//morphological closing (fill small holes in the foreground)
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		contour(imgThresholded, imgOriginal, black);

		imshow("img", img);
		imshow("black", black);
		imshow("Thresholded Image", imgThresholded); //show the thresholded image
		imshow("Original", imgOriginal); //show the original image

	}

	return 0;

}
