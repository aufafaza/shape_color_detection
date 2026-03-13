#include "Detect.hpp" 
using namespace cv; 
Detect::Detect() : rect(false), blue(false), red(false)  {} 

Detect::Detect(cv::VideoCapture v)  : v(v), rect(false), blue(false), red(false) {}; 

Detect::~Detect() = default; 

cv::Mat Detect::colorDetect(cv::Mat bgr){ 
	cv::Mat hsv; 
	
	cv::cvtColor(bgr, hsv, cv::COLOR_BGR2HSV);

	Mat red_lower, red_upper, red_mask; 
	
	Mat mask1, mask2, mask; 
	cv::inRange(hsv, cv::Scalar(0,   120, 70), cv::Scalar(10,  255, 255), mask1);
	cv::inRange(hsv, cv::Scalar(170, 120, 70), cv::Scalar(180, 255, 255), mask2);
	cv::bitwise_or(mask1, mask2, mask); 

	erode(mask, mask2, getStructuringElement(MORPH_ELLIPSE, Size(5, 5))); 
	dilate(mask, mask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5))); 
	dilate(mask, mask, getStructuringElement(MORPH_ELLIPSE, Size(5, 5))); 
	erode(mask, mask2, getStructuringElement(MORPH_ELLIPSE, Size(5, 5))); 
	
	return mask; 
} 


cv::Mat Detect::colorDetectBlue(cv::Mat bgr){ 
	cv::Mat hsv; 

	cv::cvtColor(bgr, hsv, cv::COLOR_BGR2HSV); 
	
	Mat mask1; 

	cv::inRange(hsv, cv::Scalar(110, 50, 50), cv::Scalar(130,255,255), mask1);
	return mask1; 
} 
