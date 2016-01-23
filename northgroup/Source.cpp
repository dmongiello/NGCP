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

	VideoCapture cap(0); //capture the video from web cam

	//if (!cap.isOpened())  // if not success, exit program
	//{
	//	cout << "Cannot open the web cam" << endl;
	//	return -1;
	//}


	int iLowH = 0;
	int iHighH = 50;
	iLowH = iLowH / 2;
	iHighH = iHighH / 2;

	int iLowS = 50;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;


	////Create trackbars in "Control" window
	//cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	//cvCreateTrackbar("HighH", "Control", &iHighH, 179);

	//cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	//cvCreateTrackbar("HighS", "Control", &iHighS, 255);

	//cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	//cvCreateTrackbar("HighV", "Control", &iHighV, 255);

	while (true)
	{
		//Mat imgOriginal = imread("C:/Users/Kyle/Desktop/1.png");
		Mat imgOriginal;

		bool bSuccess = cap.read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		Mat img = imgOriginal.clone();
		int width = img.size().width;
		int height = img.size().height;
		Mat black = Mat::zeros(height, width, CV_8UC3);
		threshold(img, img, 100, 255, 0);
		Mat imgHSV;


		cvtColor(img, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		Mat imgThresholded;

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

		//morphological opening (remove small objects from the foreground)
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//morphological closing (fill small holes in the foreground)
		dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		
		//for (int i = 0; i < 1; i++)
		//{
		//	blur(imgThresholded, imgThresholded, Size(15, 15));
		//	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(10, 10)));
		//	//dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_CROSS, Size(10, 10)));
		//	threshold(imgThresholded, imgThresholded, 50, 255, 0);
		//}



		Mat thresh = imgThresholded.clone();


		//contour();
		for (int i = 0; i < 1; i++)
		{

			contour(thresh, imgOriginal, black);

		}
		imshow("img", img);
		imshow("black", black);
		imshow("Thresholded Image", imgThresholded); //show the thresholded image
		imshow("Original", imgOriginal); //show the original image

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
	}

	return 0;

}