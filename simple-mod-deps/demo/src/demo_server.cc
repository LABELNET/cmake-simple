/// #pragma once

///****************************************************************************
/// Date   : 2024/01/04 16:01:35
/// Author : yuanmingzhuo
///****************************************************************************

#include <demo_server.h>

using namespace grpc;

namespace demo
{
    void run_server()
    {
        // 1. 开启插件
        grpc::EnableDefaultHealthCheckService(true);
        grpc::reflection::InitProtoReflectionServerBuilderPlugin();
        // 2. 构建服务
        ServerBuilder builder;
        builder.AddListeningPort("0.0.0.0:50051", grpc::InsecureServerCredentials());
        builder.AddChannelArgument(GRPC_ARG_KEEPALIVE_TIME_MS, 5000);
        builder.AddChannelArgument(GRPC_ARG_KEEPALIVE_TIMEOUT_MS, 10000);
        // 是否允许在没有任何未完成流的情况下发送保持连接的ping包
        builder.AddChannelArgument(GRPC_ARG_KEEPALIVE_PERMIT_WITHOUT_CALLS, 1);
        // 3.注册服务 TODO
        // 4.构建
        std::unique_ptr<Server> server(builder.BuildAndStart());
        std::cout << "[Server listening on 0.0.0.0:50051]\n"
                  << std::endl;
        // 5.启动
        server->Wait();
    }
} // namespace demo
