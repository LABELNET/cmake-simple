cmake_minimum_required(VERSION 3.18)

# 模块名称
set(MODULE_NAME demo)

# 1.可执行文件
add_executable(${MODULE_NAME})

# 2.源码，注意: 源文件代码格式，这里用的为 .cc 文件
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cc include/*.h)

# 3.目标
target_sources(${MODULE_NAME} PUBLIC ${srcs})

# 4.头文件
target_include_directories(${MODULE_NAME} PUBLIC include)

# 5. 第三方依赖 OpenCV
find_package(OpenCV CONFIG REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# 6. 第三方依赖 Spdlog
find_package(spdlog CONFIG REQUIRED)

# 7. Link 依赖
target_link_libraries(
    ${MODULE_NAME} 
    ${OpenCV_LIBRARIES}
    spdlog::spdlog
)
