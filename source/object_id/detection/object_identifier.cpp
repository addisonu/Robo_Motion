// AUTHOR: NA
// DATE: 03/24/17
// DESC: File to load classifiers and identify objects
// FILE: object_identifier.cpp

#include <iostream>
#include <cstdio>
#include <exception>
#include <fstream>
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
                std::vector<std::pair<std::string, cv::CascadeClassifier> > all_classifier;
		//cv::CascadeClassifier vehicle_cascade;
		//vehicle_cascade.load("../classification/vehicle_classifier.xml");
                try{
                    std::ifstream ifs;
                    ifs.open("all_classifier.txt", std::ifstream::in);

                    if(ifs.is_open()){
                        char cclassifier[500];
                        while(ifs.good()){
                            ifs.getline(cclassifier, 500);
                            std::string classifier(cclassifier);
                            std::size_t pos = classifier.find('|');
                            cv::CascadeClassifier tmp_cascade;
                            tmp_cascade.load(classifier.substr(pos + 1));
                            all_classifier.push_back(std::make_pair(classifier.substr(0, pos + 1), tmp_cascade));
                        }
                        ifs.close();
                    }
                }
                catch(std::exception &e){
                    std::cerr << "Error: classifiers not read from file all_classifier.txt" << std::endl << e.what() << std::endl;
                }

		// Dectect objects
                for(auto classifier_ele : all_classifier){
                    std::vector<cv::Rect> all_object;
		    classifier_ele.second.detectMultiScale(img, all_object, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
                    if(all_object.size() > 0){
                        return classifier_ele.first;
                    }
                }
	}
	catch(std::exception &e){
		std::cerr << "An unkwown error occurred. Program will now terminate." << std::endl;
	}
    return 0;
}
