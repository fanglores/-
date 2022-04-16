#pragma once
#include <opencv2/opencv.hpp>

class Camera
{
private:
	camera VideoCapture(0);
public:
	Camera();
	cv::Mat getPhoto();
};
