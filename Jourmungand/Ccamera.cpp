/////////////////////////////////////////////////////////////////////////////
///
///		Ccamera		by: Ryan Wong
///
/////////////////////////////////////////////////////////////////////////////
#define PI
#define TRUE 1





#include "Ccamera.h"
#include <thread>

/** @brief enables multi-threading and creates the canvas with the specified height and width
*
* @parameter the width of the canvas
* @parameter the height of the canvas
* @return
*/
Ccamera::Ccamera(int chosen_camera)
{
	using namespace std;
	vid.open(chosen_camera);
	vid.set(CV_CAP_PROP_FPS, 30);
	vid.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	vid.set(CV_CAP_PROP_FRAME_HEIGHT, 170);
	if (vid.isOpened() == TRUE)
	{

	}
	else
	{
		std::cout << "ERROR: Could not open Camera :(" << std::endl;
	}
	HSV_LOWER.push_back(cv::Scalar(0, 123, 134));//red
	HSV_UPPER.push_back(cv::Scalar(11, 249, 215));//orange

	HSV_LOWER.push_back(cv::Scalar(33, 164, 101));//green
	HSV_UPPER.push_back(cv::Scalar(66, 255, 227));//green
}

/** @brief nothing
*
* @parameter takes no parameters
* @return nothing
*/
Ccamera::~Ccamera()
{

}

/** @brief updates based on info recieved from cam
*
* @parameter takes no parameters
* @return nothing
*/
void Ccamera::read()
{
	
	
	//orange detection
	vid >> canvas; // put the video into the canvas to be editied
	cv::cvtColor(canvas, HSV, cv::COLOR_BGR2HSV); //change canvas from BGR to HSV
	cv::inRange(HSV, HSV_LOWER[0], HSV_UPPER[0], CSELECT);//take the HSV and remove the undesired colors

																			  //clean up the image
	cv::erode(CSELECT, dilated, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5)));//3-6
	cv::dilate(dilated, eroded, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));//3-6
	mtx.lock();
	red_area = 0;																						 //draw the rectangle around the object
	findContours(eroded, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (unsigned int i = 0; i < contours.size(); i++)
	{
		r = cv::boundingRect(contours.at(i));
		red_area = r.width * r.height;
		cv::rectangle(canvas, r, cv::Scalar(0, 0, 255), 3);
		if (largest_area <= red_area)
		{
			position_x = r.x + (r.width / 2);
			position_y = r.y + (r.height / 2);
			largest_area = red_area;
		}
	}
	mtx.unlock();
	//green detection
	cv::inRange(HSV, HSV_LOWER[1], HSV_UPPER[1], CSELECT);//take the HSV and remove the undesired colors

														  //clean up the image
	cv::erode(CSELECT, dilated, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5)));//3-6
	cv::dilate(dilated, eroded, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)));//3-6
	
	mtx.lock();
	green_area = 0;																						 //draw the rectangle around the object
	findContours(eroded, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	for (unsigned int i = 0; i < contours.size(); i++)
	{
		r = cv::boundingRect(contours.at(i));
		green_area = r.width * r.height;
		cv::rectangle(canvas, r, cv::Scalar(0, 255, 0), 3);
		if (largest_area <= green_area)
		{
			position_x = r.x + (r.width / 2);
			position_y = r.y + (r.height / 2);
			largest_area = green_area;
		}
	}
	mtx.unlock();
		
}


/** @brief drives based on info from update
*
* @parameter takes no parameters
* @return nothing
*/
void Ccamera::update()
{
	int red_area2 = red_area;
	int green_area2 = green_area;
	

	if (red_area2 < reg_area && green_area2 < reg_area)
	{
		car.forward();
		//usleep(500000);
		//car.stop();
		//std::cout << "Going forward\n";
	}
	else if (red_area2 >= reg_area && green_area2 <= reg_area)
	{
		car.left();
		//cv::waitKey(500);
		//car.stop();
		//std::cout << "Going left\n";
	}
	else if (red_area2 <= reg_area && green_area2 >= reg_area)
	{
		car.right();
		//cv::waitKey(500);
		//car.stop();
		//std::cout << "Going right\n";
	}
	else if (red_area2 > reg_area && green_area2 > reg_area)
	{
		car.stop();
		//std::cout << "I CAN SEE THE END\n";
	}
	else
	{
		car.stop();
		//std::cout << "the program isnt working :(\n";
	}
	//cv::waitKey(700);
	//car.stop();
	//cv::waitKey(1000);
	std::cout << "green area: " << green_area << std::endl;
	std::cout << "red area: " << red_area << std::endl;

}

/** @brief drives based on info from update
*
* @parameter takes no parameters
* @return nothing
*/
void Ccamera::drive()
{
	//using namespace std;
	//cv::imshow("canvas", canvas);
	//cv::waitKey(1);

}