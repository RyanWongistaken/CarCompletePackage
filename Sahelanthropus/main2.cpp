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
//Server serv2;
CTurning car;
Ccamera pi(0);
std::vector<std::string> command_list;

// Start TCP server
void serverfunc()
{
	serv.start(4618);
}

void serverfunc2()
{
	//serv2.start(4619);
}

// Send image to TCP server
void serverimagefunc()
{
	//cv::VideoCapture vid
	//vid.open(0);
		do
		{
		pi.read();
		serv.set_txim(pi.video);
		} while (cv::waitKey(10) != ' ');
	
}

void CarControl()
{
	if (pi.red_area < pi.area && pi.green_area < pi.area)
	{
		car.forward();
		std::cout << "Going forward\n";
	}
	else if (pi.red_area > pi.area && pi.green_area < pi.area)
	{
		car.left();
		std::cout << "Going left\n";
	}
	else if (pi.red_area < pi.area && pi.green_area > pi.area)
	{
		car.right();
		std::cout << "Going right\n";
	}
	else if (pi.red_area > pi.area && pi.green_area > pi.area)
	{
		car.stop();
		std::cout << "I CAN SEE THE END\n";
	}
	else
	{
		car.stop();
		std::cout << "the program isnt working :(\n";
	}
}

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
	
	// Start server2
	//td::thread t3(&serverfunc2);
	//t3.detach();

}

int main(int argc, char* argv[])
{
	/*
	char q;
	clientserver();
	std::cin >> q;
	
	while (1)
	{
	pi.read();
	CarControl();
	cv::waitKey(1000);
	std::cout << "ayy yo relax bruh\n";
	car.stop();
	cv::waitKey(500);
	}
	*/
	
	clientserver();
	int end = 0;
	using namespace std;
	while (end == 0)
	{
		serv.get_cmd(command_list);

		if (command_list.size() > 0)
		{
			std::cout << command_list[0] << endl;
			if (command_list[0] == "w" || command_list[0] == "W")
			{
				car.forward();
				cout << "going forward\n";
			}
			if (command_list[0] == "a" || command_list[0] == "A")
			{
				car.left();
				cout << "going to the right\n";
			}
			if (command_list[0] == "d"|| command_list[0] == "D")
			{
				car.right();
				cout << "going to the left\n";
			}
			if (command_list[0] == "s" || command_list[0] == "S")
			{
				car.backwards();
				cout << "going backwards\n";
			}
			if (command_list[0] == "q" || command_list[0] == "Q")
			{
				car.stop();
				cout << "ayy yo hold up\n";
			}
			if (command_list[0] == "e" || command_list[0] == "E")
			{
				car.stop();
				cout << "give up\n";
				end = 1;
			}
		}
		
	}
return 0;
}
