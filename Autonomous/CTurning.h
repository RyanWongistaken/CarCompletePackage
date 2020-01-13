////////////////////////////////////////////////////////////////
// 
// Author: Ryan Wong 
// Date Modified: 1-13-2020
// Desc: Declaring car drive system object
//
////////////////////////////////////////////////////////////////
#pragma once
#define PI
#define AIN1 3 //pin 5
#define BIN1 5 //pin 29
#define AIN2 4 //pin 7
#define BIN2 6 //pin 31
#define PWMA 2 //pin 3
#define PWMB 17 //pin 11

#ifdef Win
#include "stdafx.h"
#endif // Win

#ifdef PI
#include "CControl.h"
#endif // PI

class CTurning : public CControl
{
private:

public:
	CControl Car;
	CTurning();
	~CTurning();
	void forward();
	void stop();
	void left();
	void right();
	void backwards();
	void turbo();
};