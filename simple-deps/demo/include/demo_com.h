/// #pragma once

///****************************************************************************
/// Date   : 2024/01/04 15:33:28
/// Author : yuanmingzhuo
///****************************************************************************

/// 测试仅头文件定义

#include <iostream>

namespace demo
{
    static void demo_com(std::string message)
    {
        std::cout << message + " MESSAGE " << std::endl;
    }
}