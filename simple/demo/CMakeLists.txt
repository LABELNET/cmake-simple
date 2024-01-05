cmake_minimum_required(VERSION 3.18)

# 1.可执行文件
add_executable(demo)

# 2.源码，注意: 源文件代码格式，这里用的为 .cc 文件
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc include/*.h)

# 3.目标
target_sources(demo PUBLIC ${srcs})

# 4.头文件
target_include_directories(demo PUBLIC include)