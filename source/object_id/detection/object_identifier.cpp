// AUTHOR: NA
// DATE: 03/24/17
// DESC: File to load classifiers and identify objects
// FILE: object_identifier.cpp

#include <iostream>
#include <cstdio>
#include <exception>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char **argv)
{
	try{
	// Load image
	if(argv[1] == nullptr || argv[1] == '\0'){
		std::cerr << "No image passed as program argument." << std::endl; 
		}
		cv::Mat img;
		img = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

	// Load classifiers
	cv::CascadeClassifier vehicle_cascade;
	vehicle_cascade.load("../classification/vehicle_classifier.xml");

	// Dectect objects
	std::vector<cv::Rect> all_vehicle;
	vehicle_cascade.detectMultiScale(img, all_vehicle, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
		
	}
	catch(std::exception &e){
		std::cerr << "An unkwown error occurred. Program will now terminate." << std::endl;
	}
    return 0;
}
