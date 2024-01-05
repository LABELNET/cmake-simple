/// #pragma once

///****************************************************************************
/// Date   : 2024/01/04 11:52:20
/// Author : yuanmingzhuo
///****************************************************************************

#include <demo_utils.h>

namespace demo 
{
    float compute_circle_area(float r)
    {
        return PI * r * r;
    }

    float compute_rect_area(float w,float h)
    {
        return w * h;
    }
}