cmake_minimum_required(VERSION 3.18)

# 1.源码，注意: 源文件代码格式，这里用的为 .cc 文件 , 若为 cpp 后缀自行添加
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc include/*.h)

# 2.静态链接库
# add_library(store STATIC ${srcs})
# 2.1 动态链接库
# add_library(store SHARED ${srcs})
# 2.2 对象链接库(推荐)
add_library(store OBJECT ${srcs})
# 3.头文件
target_include_directories(store PUBLIC include)