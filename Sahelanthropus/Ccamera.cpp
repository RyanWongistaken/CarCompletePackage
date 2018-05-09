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
	vid.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	vid.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
	//vid.set(CV_CAP_PROP_FPS, 30);
	if (vid.isOpened() == TRUE)
	{

	}
	else
	{
		std::cout << "ERROR: Could not open Camera :(" << std::endl;
	}
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
	mtx.lock();
	//orange detection
	vid >> canvas; // put the video into the canvas to be editied

	cv::cvtColor(canvas, video, cv::COLOR_BGR2GRAY);
	mtx.unlock();

	
}


/** @brief drives based on info from update
*
* @parameter takes no parameters
* @return nothing
*/
void Ccamera::update()
{


}

/** @brief drives based on info from update
*
* @parameter takes no parameters
* @return nothing
*/
void Ccamera::drive()
{
	using namespace std;
	cv::imshow("canvas", canvas);
	cv::waitKey(1);

}