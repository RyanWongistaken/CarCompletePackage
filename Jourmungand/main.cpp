#define PI
#define TRUE 1

#ifdef win
#include <string>
#include <iostream>
#include <thread>

#include "Client.h"
#include "Server.h"
#include "Serial.h" // Must include Windows.h after Winsock2.h, so Serial must include after Client/Server
#include "stdafx.h"
// OpenCV Include
#include "opencv.hpp"
// OpenCV Library
#pragma comment(lib,".\\opencv\\lib\\opencv_world310d.lib")
#endif // win




#ifdef PI
#include <unistd.h>
#include <opencv2/opencv.hpp>
#include "pigpio.h"
#endif // PI

#include "server.h"
#include "Ccamera.h"
#include "CTurning.h"

////////////////////////////////////////////////////////////////
// Demo client server communication
////////////////////////////////////////////////////////////////
Server serv;
CTurning car;
Ccamera pi(0);
// Start TCP server
/*
void serverfunc()
{
	serv.start(4618);
}

// Send image to TCP server
void serverimagefunc()
{
	//cv::VideoCapture vid;
	pi.read();
	//vid.open(0);


		do
		{
			//cv::Mat frame;
			//vid >> frame;
			serv.set_txim(pi.canvas);
		} while (cv::waitKey(10) != ' ');
	
}
*/
/*
void CarControl()
{
	if (pi.red_area < 7000 && pi.green_area < 7000)
	{
		car.forward();
		usleep(500000);
		car.stop();
		//std::cout << "Going forward\n";
	}
	else if (pi.red_area >= 7000 && pi.green_area <= 7000)
	{
		car.left();
		usleep(680000);
		car.stop();
		//std::cout << "Going left\n";
	}
	else if (pi.red_area <= 7000 && pi.green_area >= 7000)
	{
		car.right();
		usleep(680000);
		car.stop();
		//std::cout << "Going right\n";
	}
	else if (pi.red_area > 5500 && pi.green_area > 5500)
	{
		car.stop();
		//std::cout << "I CAN SEE THE END\n";
	}
	else
	{
		car.stop();
		//std::cout << "the program isnt working :(\n";
	}
}
*/
/*
void clientserver()
{
	std::string str;
	cv::Mat im;

	// Start server
	std::thread t1(&serverfunc);
	t1.detach();

	// Start image send to server
	std::thread t2(&serverimagefunc);
	t2.detach();
	
	

}
*/
int main(int argc, char* argv[])
{

	char q;
	//clientserver();
	std::cin >> q;
		
	//pi.drive();

	while (1)
	{
	pi.read();
	pi.update();
	//std::cout << "green area: " << pi.green_area << std::endl;
	//std::cout << "red area: " << pi.red_area << std::endl;
	//CarControl();
	//usleep(750000);
	}
	
	/*
	while(1)
	{
	pi.read();
	std::cout << "green area: " << pi.green_area << std::endl;
	std::cout << "red area: " << pi.red_area << std::endl;
	pi.drive();
	}
	return 0;
*/
}
