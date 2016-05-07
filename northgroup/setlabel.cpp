#include "main.hpp"


using namespace cv;
using namespace std;



void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour)
{
	int fontface = cv::FONT_HERSHEY_SIMPLEX;
	double scale = 0.4;
	int thickness = 1;
	int baseline = 0;

	cv::Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);
	cv::Rect r = cv::boundingRect(contour);
    
    
    
	cv::Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
 	cv::rectangle(im, pt + cv::Point(0, baseline), pt + cv::Point(text.width, -text.height), CV_RGB(255, 255, 255), CV_FILLED);
	cv::putText(im, label, pt, fontface, scale, CV_RGB(0, 0, 0), thickness, 8);
    

    double xNot = r.x + ((r.width - text.width) / 2);
    double yNot = r.y + ((r.height + text.height) / 2);
    
    
    cout << "x: " << xNot << " y: " << yNot << endl;
    //Target t;
    //t.mathEquations(xNot, yNot);
    
    
};


