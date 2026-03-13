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

		void shapeDetect(cv::Mat imgDil, cv::Mat img);
		bool isValid(); 
		
}; 
