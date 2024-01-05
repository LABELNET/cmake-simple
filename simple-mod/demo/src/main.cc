/// #pragma once

///****************************************************************************
/// Date   : 2024/01/04 10:51:39
/// Author : yuanmingzhuo
///****************************************************************************

#include <iostream>
#include <demo_utils.h>

/// 本地模块依赖
#include <store_utils.h>

using namespace std;
using namespace demo;

int main()
{
    cout << "Demo : " << compute_circle_area(100) << endl;
    // 测试本地依赖
    string dogName = "DogDemeStore";
    cout << "Demo Store : " << store::dogSpeak(dogName) << endl;
    // 结束
    cout << "Uan Store End" << endl;
}