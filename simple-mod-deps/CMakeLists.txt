cmake_minimum_required (VERSION 3.18)

# 项目名称
set (PROJECT_NAME simple-mod-deps)
project (${PROJECT_NAME} VERSION 0.1.0)

# 1.编译类型
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif ()

# 2. C++ 标准库
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_CXX_EXTENSIONS OFF)

# 3. 第三方库
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake;${CMAKE_MODULE_PATH}")

# 3.1 第三方库依赖环境, 可自行源码编译指定，也可使用 vcpkg 下载的包
set (ZLIB_ROOT D:/Software/vcpkg/packages/zlib_x64-windows)
set (OPENSSL_ROOT_DIR D:/Software/vcpkg/packages/openssl_x64-windows)

# 4.工程名称
project (${PROJECT_NAME} LANGUAGES CXX)

# 5.主模块 main
add_subdirectory (demo)

# 6.子模块 store
add_subdirectory (store)

# 7.项目打包
set (CPACK_PROJECT_NAME ${PROJECT_NAME})
set (CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include (CPack)

# 8. Windows 异常
if (WIN32)
    add_definitions (-DNOMINMAX -D_USE_MATH_DEFINES)
endif ()

# 9.使用编译缓存，提升编译速度
if (NOT MSVC)
    find_program (CCACHE_PROGRAM ccache)

    if (CCACHE_PROGRAM)
        message (STATUS "Found CCache: ${CCACHE_PROGRAM}")
        set_property (GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
        set_property (GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
    endif ()
endif ()
