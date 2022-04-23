#pragma once
#include <opencv2/opencv.hpp>

class Camera
{
private:
	cv::VideoCapture camera;
public:
	Camera();
	cv::Mat getPhoto();
};
