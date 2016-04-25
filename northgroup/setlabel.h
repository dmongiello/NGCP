#ifndef SETLABEL_H
#define SETLABEL_H

class setlabel {
private: 
	bool tlabel = false;
public:
	void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);
};
#endif
