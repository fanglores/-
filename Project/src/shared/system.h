#pragma once

#include <opencv2/opencv.hpp>

#include "camera.h"
#include "generator.h"

enum class SystemState
{
	STARTING,
	WORKING,
	STARTING_GENERATOR,
	STOPPING_GENERATOR,
	STOPPING,
	OFF,
	ERROR
};

class System
{
private:
	SystemState state;

    Camera camera;
	Generator generator;

    cv::Mat previousPhoto, currentPhoto;

	int Init();
public:
    System();

	int Run();
	int Stop();
    void updatePhoto();
};

