////////////////////////////////////////////////////////////////
// 
// Author: Ryan Wong 
// Date Modified: 1-13-2020
// Desc: Autonmous Car using Machine vision through OpenCV
//
////////////////////////////////////////////////////////////////
#define PI
#define TRUE 1

#ifdef win
#include <string>
#include <iostream>
#include <thread>

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
#endif 

#include "server.h"
#include "Ccamera.h"
#include "CTurning.h"


Ccamera pi(0); // Camera Object
int main(int argc, char* argv[])
{
	char q;
	std::cin >> q;

	while (1)
	{
	pi.read();
	pi.update();
	}
}
