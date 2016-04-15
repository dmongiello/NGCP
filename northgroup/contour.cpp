                      
#include "main.hpp"
#include <fstream>
using namespace cv;
using namespace std;


// Countour()
// Perams: imgThresholded, imgOrginal, img
// Returns void.
// Passes the image by reference and cacluates the countours to estamate a circle. 

void contour(Mat& imgThresholded, Mat& imgOriginal, Mat& img, Target  targetArray)
{
    Mat bw;
    Canny(imgThresholded, bw, 0, 50, 5);
    vector<std::vector<cv::Point> > contours;
    
    findContours(bw, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
    /// Approximate contours to polygons + get bounding rects and circles
    vector<vector<Point> > contours_draw(contours.size());
    vector<cv::Point> contours_poly;
    
    for (int i = 0; i < contours.size(); i++) //set labels or identify shapes in this loop
    {
        approxPolyDP(Mat(contours[i]), contours_poly, 1, true);
        approxPolyDP(Mat(contours[i]), contours_draw[i], 1, true);
        
        double area = cv::contourArea(contours[i]);
        cv::Rect r = cv::boundingRect(contours[i]);
        int radius = r.width / 2;
        
        if (abs(1 - ((double)r.width / r.height)) <= 0.2 && abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2 && area > 200)
        {
            // Set target as found
            targetArray.setFound(true);
            time_t timer = time(nullptr);
            
            //this is how you get the time stamp to be a char * of time and date.
            targetArray.setTime(asctime(localtime(&timer)));
            
            targetArray.setPosition(1000);
            targetArray.setFound(true);
            
            
            cout << targetArray.str();
            ofstream myfile;
            myfile.open ("targeting.text", ios::out | ios::app);
            myfile << targetArray.str();

            setLabel(imgOriginal, "CIR", contours[i]);
            Mat drawing = Mat::zeros(imgThresholded.size(), CV_8UC3);
            for (int i = 0; i< contours.size(); i++    )
            {
                Scalar color = Scalar(0, 0, 0);
                drawContours(imgOriginal, contours_draw, i, color, 5, 8, vector<Vec4i>(), 0, Point());
                drawContours(img, contours_draw, i, color, 5, 8, vector<Vec4i>(), 0, Point());
            }
        }
    }
}
