#include <iostream> 
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "src/Detect.hpp" 


using namespace std;
using namespace cv;

int main(){ 
	VideoCapture cap(0); 

	if (!cap.isOpened()){
		return -1; 
	} 
	Detect filter, filter2; 
	cv::Mat frame, redMask, blueMask; 

	while (true) { 
		cap >> frame; 
		if (frame.empty()) break; 

		redMask = filter.colorDetect(frame); 
		blueMask = filter2.colorDetectBlue(frame);
		imshow("Original", frame); 
		imshow("red mask", redMask);
		imshow("blue mask", blueMask); 
		
		if (waitKey(1) == 'q') break; 
	}

	cap.release(); 
	destroyAllWindows();
	return 0; 
} 
