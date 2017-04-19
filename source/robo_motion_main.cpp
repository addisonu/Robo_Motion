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
    if(argv[1] == nullptr || argv[1] == '\0'
		|| argv[2] == nullptr || argv[2] == '\0'
		|| argv[3] == nullptr || argv[3] == '\0'
		|| argv[4] == nullptr || argv[4] == '\0'
		|| argv[5] == nullptr || argv[5] == '\0'
		|| argv[6] == nullptr || argv[6] == '\0'){
            std::cerr << "The correct number of arguments were not passed.\n" << std::endl
			<< "Arguments should be passed as:\nRoboMotion <out_file> <in_file> <kb> "
			<< "<rule> <classifier> <classifier_list>\n" << std::endl
			<< "For more information about running the program, read the help file " 
			<< "Robo_Motion/documentation/how_to/run_project.txt" << std::endl;
    }
	std::string out_file(argv[1]);
	std::string in_file(argv[2]);
std::cout << "vid path: " << in_file << std::endl;// debugging
	std::string kb(argv[3]);
	std::string rule(argv[4]);
	std::string classifier_dir(argv[5]);
	std::string classifier_list(argv[6]);
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
                ifs.open(classifier_list, std::ifstream::in);

                if(ifs.is_open()){
std::cout << "All_classifier file open" << std::endl; //debbuging
                    char cclassifier[500];
					ifs.getline(cclassifier, 500);

                    while(ifs.good()){
std::cout << "Now loading" << std::endl; //debbuging
                        std::string classifier(cclassifier);
                        std::size_t pos = classifier.find('|');
                        cv::CascadeClassifier tmp_cascade;
                        classifier = classifier_dir + '/' + classifier.substr(pos + 1);
std::cout << "classifier path : " << classifier << std::endl;// debugging
						//if(!tmp_cascade.load(classifier.substr(pos + 1))){
						if(!tmp_cascade.load(classifier)){
							throw std::invalid_argument("Classifier not loaded");
						}
                        all_classifier.push_back(std::make_pair(classifier.substr(0, pos + 1), tmp_cascade));
                        ifs.getline(cclassifier, 500);
                    }
                    ifs.close();
                }
            }
            catch(std::exception &e){
                std::cerr << "Error: classifier(s) not read from file all_classifier.txt" << std::endl << e.what() << std::endl;
            }
            // Dectect objects
            
			cv::VideoCapture cap(in_file.c_str());
			if(!cap.isOpened()){
				std::cerr << "Video not opened" << std::endl;
				return -1;
			}
//			cv::namedWindow("Vid", 1);
			cv::Mat *frame;
			frame = new cv::Mat();
			do{
std::cout << "New frame read" << std::endl; //debbuging
				cap >> *frame;
				if(frame->empty()){
					std::cout << "Frame empty" << std::endl;
					continue;
				}			
//				cv::imshow("Vid", *frame);
//				if(cv::waitKey(30) >= 0){
//					break;
//				}
//				cv::Size mat_size = frame->size();

				for(auto classifier_ele : all_classifier){
std::cout << "Loop through classifiers" << std::endl; //debbuging
					std::vector<cv::Rect> all_object;
					classifier_ele.second.detectMultiScale(*frame, all_object, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
					if(all_object.size() > 0){
						classified_object_name = classifier_ele.first;
						std::cout << "classified_object_name: " << classified_object_name << std::endl;// debugging
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
