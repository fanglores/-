#include "camera.h"

Camera::Camera() : camera(cv::VideoCapture(0))
{}

cv::Mat Camera::getPhoto()
{
	cv::Mat frame;
	camera >> frame;
	
	return frame;
}
//errors processing (?)