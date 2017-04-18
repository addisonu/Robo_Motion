// AUTHOR: NA
// DATE: 04/17/17
// DESC: Entry point for program
// FILE: robo_motion_main.cpp

/* 
* NOTE: to compile program: 
* command #1: export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
* command #2: g++ -std=c++11 <source_file> `pkg-config opencv --cflags --libs`
*/

#include <iostream>
#include <cstdio>
#include <exception>
#include <fstream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char **argv)
{
    // Extract arguments
    if(argv[1] == nullptr || argv[1] == '\0'){
            std::cerr << "The correct number of arguments were not passed.\n" << std::endl
			<< "Arguments should be passed as:\nRoboMotion <out_file> <in_file> <kb> "
			<< "<rule> <classifier> <classifier_list>\n" << std::endl
			<< "For more information about running the program, read the help file " 
			<< "Robo_Motion/documentation/how_to/run_project.txt" << std::endl;
    }
    try{
            // Load image
            //cv::Mat img;
            //img = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

			// debugging start
/*
			std::cerr << "video name: " << argv[1] << std::endl;
			cv::VideoCapture cap(argv[1]);
			if(!cap.isOpened()){
				std::cerr << "Video not opened" << std::endl;
				return -1;
			}
			cv::namedWindow("Vid", 1);
			cv::Mat *frame;
			frame = new cv::Mat();
			do{
				cap >> *frame;
				cv::imshow("Vid", *frame);
				if(cv::waitKey(30) >= 0){
					break;
				}
				cv::Size mat_size = frame->size();
			}while(!frame->empty());
			// debugging stop
*/
            
            // Load classifiers
            std::vector<std::pair<std::string, cv::CascadeClassifier> > all_classifier;
			std::string classified_object_name;
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
            
			cv::VideoCapture cap(argv[1]);
			if(!cap.isOpened()){
				std::cerr << "Video not opened" << std::endl;
				return -1;
			}
//			cv::namedWindow("Vid", 1);
			cv::Mat *frame;
			frame = new cv::Mat();
			do{
				cap >> *frame;
//				cv::imshow("Vid", *frame);
//				if(cv::waitKey(30) >= 0){
//					break;
//				}
//				cv::Size mat_size = frame->size();

				for(auto classifier_ele : all_classifier){
					std::vector<cv::Rect> all_object;
					classifier_ele.second.detectMultiScale(*frame, all_object, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
					if(all_object.size() > 0){
						classified_object_name = classifier_ele.first;
						// get object name to pass to ontology
						// LEFT OFF
						frame->release();
						break;
					}
				}
			}while(!frame->empty());
    }
    catch(std::exception &e){
            std::cerr << "An unkwown error occurred. Program will now terminate." << std::endl;
    }
return 0;
}
