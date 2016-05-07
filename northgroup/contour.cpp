                      
#include "main.hpp"
#include <fstream>
using namespace cv;
using namespace std;


// Countour()
// Perams: imgThresholded, imgOrginal, img
// Returns void.
// Passes the image by reference and cacluates the countours to estamate a circle. 

void contour(Mat& imgThresholded, Mat& imgOriginal, Mat& img, Target targetArray)
{
    Mat bw;
    //Finding the Edges of the image
    Canny(imgThresholded, bw, 0, 50, 5);
    vector<std::vector<cv::Point> > contours;
    
    //go thru edges until the contours are completed
    findContours(bw, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
   
    /// Approximate contours to polygons + get bounding rects and circles
    vector<vector<Point> > contours_draw(contours.size());
    vector<cv::Point> contours_poly;
    
    for (int i = 0; i < contours.size(); i++) //set labels or identify shapes in this loop
    {
        
        //Area inside the Contours
        double area = cv::contourArea(contours[i]);
        
        //Rectangles = A rectangular bound around circle
        //countours/ellipse.
        cv::Rect rectangle = cv::boundingRect(contours[i]);
        int radius = rectangle.width / 2;
        //Checking for if width and height are similar enough to be a circle
        bool BoundingRecForCircles = abs(1 - ((double)rectangle.width / rectangle.height)) <= 0.3;
        //Theorectical Error = 1 - (Actual Area / theorectical area)
        bool Error = abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2;
        
        bool AreaBound = (area < 1400 && area > 1100);
       
        
        
        if (BoundingRecForCircles && Error && AreaBound)
       {
           
            setLabel(imgOriginal, "CIR", contours[i]);
           
            
        }
    }
}
