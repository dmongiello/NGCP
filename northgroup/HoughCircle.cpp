//Kyle Winterer
#include "main.hpp"

using namespace cv;
using namespace std;

void HoughCircle(Mat imgThresholded, Mat imgOriginal)
{
	Mat img = imgOriginal.clone();
	for (int i = 0; i<imgThresholded.rows; i++)

	{

		for (int j = 0; j<imgThresholded.cols; j++)

		{
			if (imgThresholded.at<uchar>(i, j) == 255)
			{
				img.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
			}
			else
			{
				img.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
			}

		}

	}

	Mat gray;
	cvtColor(img, gray, CV_BGR2GRAY);

	GaussianBlur(gray, gray, Size(9, 9), 2, 2);

	vector<Vec3f> circles;
	HoughCircles(gray, circles, CV_HOUGH_GRADIENT, 1, gray.rows / 8, 200, 100, 0, 0);


	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);

		circle(imgOriginal, center, 3, Scalar(0, 0, 0), -1, 8, 0);
		// circle outline
		circle(imgOriginal, center, radius, Scalar(0, 0, 0), 3, 8, 0);

		targetfound(center, radius);
	}

}