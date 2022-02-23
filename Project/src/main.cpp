#include <opencv2/opencv.hpp>
#include "opencv2/core/utils/logger.hpp"
#include <iostream>

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

        cv::imshow("Webcam", frame);

        if (cv::waitKey(1) == int('q'))
            break;
    }

    return 0;
}
