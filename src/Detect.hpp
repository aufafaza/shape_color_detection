#include <opencv2/opencv.hpp>
class Detect { 
	private:
		cv::VideoCapture v; 
		bool rect; 
		bool blue;
		bool red; 
	public: 
		Detect(); 
		Detect(cv::VideoCapture v); 
		~Detect(); 
		cv::Mat colorDetect(cv::Mat bgr);
		cv::Mat colorDetectBlue(cv::Mat bgr); 

		cv::Mat shapeDetect(cv::Mat mask, cv::Mat originalFrame);
		bool isValid(); 
		
}; 
