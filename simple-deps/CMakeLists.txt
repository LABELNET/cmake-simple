cmake_minimum_required(VERSION 3.18)

# 项目名称
set(PROJECT_NAME simple-deps)
project(${PROJECT_NAME} VERSION 0.1.0)

# 1.编译类型
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# 2. C++ 标准库
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 3. 第三方库
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake;${CMAKE_MODULE_PATH}")

# 4.工程名称
project(${PROJECT_NAME} LANGUAGES CXX)

# 5.主模块 main
add_subdirectory(demo)

# 6.打包器
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)