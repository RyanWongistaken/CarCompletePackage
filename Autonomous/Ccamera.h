////////////////////////////////////////////////////////////////
// 
// Author: Ryan Wong 
// Date Modified: 1-13-2020
// Desc: Creating OpenCV object
//
/////////////////////////////////////////////////////////////////
#pragma once
#define PI

#ifdef PI
#include <opencv2/opencv.hpp>
#include "pigpio.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>

#include <fstream>
#include <thread>
#include <mutex>
#include <cmath>
#endif // PI

class Ccamera 
{
private:
	std::mutex mtx;
	
public:
	int area = 75;
	cv::Mat canvas;
	cv::Mat video;
	cv::VideoCapture vid;
	cv::Mat frame, HSV, CSELECT, eroded, dilated;
	cv::Rect r;
	std::vector<cv::Vec4i> hierarchy;
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Point> contour;
	std::vector<cv::Scalar> HSV_LOWER;
	std::vector<cv::Scalar> HSV_UPPER;
	int position_y = 0;
	int position_x = 0;
	int red_area = 0;
	int green_area = 0;
	int largest_area = 0;

	Ccamera(int chosen_camera);
	~Ccamera();
	void update();
	void drive();
	void read();
};