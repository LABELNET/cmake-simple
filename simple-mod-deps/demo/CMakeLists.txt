cmake_minimum_required (VERSION 3.18)

# 1.可执行文件
add_executable (demo)

# 2.源码，注意: 源文件代码格式，这里用的为 .cc 文件
file (GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc include/*.h)

# 3.目标
target_sources (demo PUBLIC ${srcs})

# 4.头文件
target_include_directories (demo PUBLIC include)

# 5.第三方依赖 GRPC

find_package (gRPC CONFIG REQUIRED)
find_package (Threads REQUIRED)

# 6.Link 依赖
target_link_libraries (
    demo PUBLIC
    store
    gRPC::grpc++
    gRPC::grpc++_reflection
)