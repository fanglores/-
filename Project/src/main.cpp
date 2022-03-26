#include <opencv2/opencv.hpp>
#include "opencv2/core/utils/logger.hpp"
#include <iostream>

enum GeneratorMode
{
    AUTOMATIC,
    MANUAL
};

enum GeneratorState
{
    ON,
    STARTING,
    STOPPING,
    OFF
};

class Camera
{

};

class Generator
{
private:
    GeneratorState state = GeneratorState::OFF;
    GeneratorMode mode = GeneratorMode::AUTOMATIC;

    int RunManual()
    {
        state = GeneratorState::ON;

        //run in manual mode

        return 0;
    }

    int RunAutomatic()
    {
        state = GeneratorState::ON;

        //run in auto mode

        return 0;
    }

public:
    int Start(GeneratorMode start_mode)
    {
        state = GeneratorState::STARTING;
        mode = start_mode;

        //some starting operations here

        if (mode == GeneratorMode::AUTOMATIC) RunAutomatic();
        else RunManual();

        return 0;
    }

    int Stop()
    {
        state = GeneratorState::STOPPING;

        //some stop operations here

        state = GeneratorState::OFF;

        return 0;
    }
};

class CloudStorage
{

};

class MainMachine
{
private:
    Camera camera;
    cv::Mat previousPhoto, currentPhoto;
public:
    MainMachine()
    {
    }
    void updatePhoto()
    {
    }
};


int main()
{   
    cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);
    cv::VideoCapture camera(0);

    if (!camera.isOpened()) 
    {
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return 1;
    }

    cv::Mat frame;

    while (true) 
    {
        camera >> frame;

        cv::imshow("Webcam.ru", frame);

        if (cv::waitKey(1) == int('q'))
            break;
    }

    return 0;
}
