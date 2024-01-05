/// #pragma once

///****************************************************************************
/// Date   : 2024/01/04 10:51:39
/// Author : yuanmingzhuo
///****************************************************************************

#include <iostream>
#include <demo_utils.h>
#include <demo_com.h>

#include <opencv4/opencv2/opencv.hpp>
#include <spdlog/spdlog.h>

using namespace std;
using namespace demo;
using namespace cv;

int main()
{

    // 1. 日志
    spdlog::error("1. I'im error log message !!! ");

    // 2. 测试依赖库
    auto image = cv::imread("../../INSTALL.jpg", cv::IMREAD_COLOR);
    cv::imshow("test", image);
    cv::waitKey(3000);

    // 3. local fun
    cout << "3. LOCAL FUN : " << compute_circle_area(100) << endl;

    // 4. local header fun
    demo_com("4. Local Header");
    // 5. end
    cout << "5. Uan Store" << endl;
}