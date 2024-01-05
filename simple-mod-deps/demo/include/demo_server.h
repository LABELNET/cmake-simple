/// #pragma once

///****************************************************************************
/// Date   : 2024/01/04 16:00:40
/// Author : yuanmingzhuo
///****************************************************************************

#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>

#include <iostream>


namespace demo
{
    void run_server();
}