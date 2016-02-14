#include "main.hpp"

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
    
    VideoCapture cap(0); //capture the video from web cam
    
    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the web cam" << endl;
        return -1;
    }
    int iLowH = 0;
    int iHighH = 25;
    int iLowS = 50;
    int iHighS = 255;
    int iLowV = 0;
    int iHighV = 255;
    
    
    while (true)
    {
        Mat imgOriginal;
        Mat imgThresholded;
        bool bSuccess = cap.read(imgOriginal); // read a new frame from video
        
        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }
        
        Mat black = Mat::zeros(imgOriginal.size().height, imgOriginal.size().width, CV_8UC3);
        threshold(  imgOriginal,   imgOriginal, 100, 255, 0);
        Mat imgHSV;
        //Convert the captured frame from RGB to HSV
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
        //Threshold the image
        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded);
        // Clean all the small circles from the image
        cleanImage(imgThresholded);
        //contour()
        contour(imgThresholded, imgOriginal, black);
        //show the original image
        imshow("Original", imgOriginal);
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
    
    return 0;
    
}
