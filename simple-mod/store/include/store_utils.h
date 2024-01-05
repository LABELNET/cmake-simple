/// #pragma once

///****************************************************************************
/// Date   : 2024/01/04 13:28:55
/// Author : yuanmingzhuo
///****************************************************************************

#define DOG "WANG WANG WANG"
#define CAT "Miao Miao Miao"

#include <iostream>
#include <string>

namespace store
{

    // 狗吆喝
    std::string dogSpeak(std::string &name);

    // 猫吆喝
    std::string catSpeak(std::string &name);

}