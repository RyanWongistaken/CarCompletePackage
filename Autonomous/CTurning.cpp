////////////////////////////////////////////////////////////////
// 
// Author: Ryan Wong 
// Date Modified: 1-13-2020
// Desc: Drive system functions
//
////////////////////////////////////////////////////////////////
#define PI
#define TRUE 1

#include "CTurning.h"
/** @brief constructor that determines motor speed for the two DC motors
*
* 
* @return nothing
*/
CTurning::CTurning()
{
	Car.set_data(SERVO, PWMA, 157);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 152);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 0);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 0);//GPIO5 ---> Bi1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO6 ---> Bi2
}

/** @brief Empty Destructor
*
* 
* @return nothing
*/
CTurning::~CTurning()
{

}

/** @brief Moves the car forwards
*
* 
* @return nothing
*/
void CTurning::forward()
{
	Car.set_data(SERVO, PWMA, 148);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 150);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 1);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 1);//GPIO5 ---> Bi1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO6 ---> Bi2
}

/** @brief Movs the car backwards
*
* 
* @return nothing
*/
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

/** @brief Applies the breaks
*
* 
* @return nothing
*/
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

/** @brief Turns left
*
* 
* @return nothing
*/
void CTurning::left()
{
	Car.set_data(SERVO, PWMA, 175);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 157);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 1);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 0);//GPIO5 ---> Bi1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO6 ---> Bi2
}

/** @brief Turns right
*
* 
* @return nothing
*/
void CTurning::right()
{
	Car.set_data(SERVO, PWMA, 180);//CONTROL THE SPEED (GPIO2)
	Car.set_data(SERVO, PWMB, 152);//CONTROL THE SPEED (GPIO17)
	//wheel connected to channel A
	Car.set_data(DIGITAL, AIN1, 0);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, AIN2, 0);//GPIO4 ---> Ai2
	//Wheel connected to Channel B
	Car.set_data(DIGITAL, BIN1, 1);//GPIO3 ---> Ai1
	Car.set_data(DIGITAL, BIN2, 0);//GPIO4 ---> Ai2
}

/** @brief Turbo speed 
*	(Spins out the wheels most of the time) 
* 
* @return nothing
*/
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