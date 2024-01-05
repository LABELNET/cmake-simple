/// #pragma once

///****************************************************************************
/// Date   : 2024/01/04 13:33:54
/// Author : yuanmingzhuo
///****************************************************************************

#include <store_utils.h>

namespace store
{

    std::string dogSpeak(std::string &name)
    {
        return name + " : " + DOG;
    }

    std::string catSpeak(std::string &name)
    {
        return name + " : " + CAT;
    }

} // namespace store
