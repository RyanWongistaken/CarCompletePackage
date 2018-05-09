#define PI
#define TRUE 1


#include "CTurning.h"

CTurning::CTurning()
{
	Car.set_data(SERVO, PWMA, 150);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 152);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 0);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 0);//GPIO5 ---> Bi1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO6 ---> Bi2
}

CTurning::~CTurning()
{

}

void CTurning::forward()
{
	Car.set_data(SERVO, PWMA, 150);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 152);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 1);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 1);//GPIO5 ---> Bi1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO6 ---> Bi2
}

void CTurning::backwards()
{
	Car.set_data(SERVO, PWMA, 150);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 152);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 0);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 1);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 0);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, BIN2, 1);//GPIO4 ---> Ai2
}

void CTurning::stop()
{
	Car.set_data(SERVO, PWMA, 150);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 152);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 0);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 0);//GPIO5 ---> Bi1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO6 ---> Bi2

}

void CTurning::left()
{
	Car.set_data(SERVO, PWMA, 150);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 152);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 1);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 0);//GPIO5 ---> Bi1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO6 ---> Bi2
}

void CTurning::right()
{
	Car.set_data(SERVO, PWMA, 150);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 152);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 0);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 1);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO4 ---> Ai2
}

void CTurning::turbo()
{
	Car.set_data(SERVO, PWMA, 255);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 255);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 1);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 1);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO4 ---> Ai2
}