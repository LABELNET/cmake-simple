
# 单模块工程 + 第三方依赖

CMake 单模块工程，这是一个示例工程

- simple-deps   , 项目名称
- cmake         , 第三方依赖
- demo          , 主模块 main

## 目录结构

```
$ .SIMPLE-DEPS      
│   CMakeLists.txt                 # 项目根 CMakeLists.txt , 用于项目配置
│   README.md                      # 说明文档，无关
├───.vscode                        # 头文件路径配置
│       c_cpp_properties.json
├───cmake                          # 第三方依赖文件夹
├───build                          # CMake 编译输出
└───demo                           # 主模块
    │   CMakeLists.txt             # 主模块 CMakeLists.txt                    
    ├───include                    # 源码：头文件文件夹
    │       demo_utils.h
    └───src                        # 源码: 代码文件夹
            demo_utils.cc
            main.cc
```

## 第三方依赖

### MSYS2 

Windows 使用 MSYS2 的 UCRT64 ，使用终端命令 `pacman` 安装依赖环境

```
pacman -S mingw-w64-x86_64-opencv
```

常用包，可以在这里查询安装 `https://packages.msys2.org/queue?build_type=ucrt64`

比如，安装日志依赖

```
pacman -S mingw-w64-ucrt-x86_64-spdlog
```

### find_package

`find_package` CMake 约定的依赖路径规则，对应依赖包存在 `XXXConfig.cmake` 文件，而 `/usr/lib/cmake`是 CMake 约定好存放路径，第三方程序包配置文件放到这个路径下

**1. find_package 命令**

- find_package(OpenCV)

查找名为 OpenCV 的包，找不到不报错，事后可以通过 ${OpenCV_FOUND} 查询是否找到。

- find_package(OpenCV QUIET)

查找名为 OpenCV 的包，找不到不报错，也不打印任何信息。

- find_package(OpenCV REQUIRED) # 最常见用法

查找名为 OpenCV 的包，找不到就报错（并终止 cmake 进程，不再继续往下执行）。

- find_package(OpenCV 2.0.1 REQUIRED)

查找版本在 2.0.1 以上的 OpenCV 包（version >= 2.0.1）。

**2. Window搜索路径**

```
<prefix>/
<prefix>/cmake/
<prefix>/<name>*/
<prefix>/<name>*/cmake/
<prefix>/<name>*/(lib/<arch>|lib*|share)/cmake/<name>*/
<prefix>/<name>*/(lib/<arch>|lib*|share)/<name>*/
<prefix>/<name>*/(lib/<arch>|lib*|share)/<name>*/cmake/

# 说明
<prefix> 是变量 ${CMAKE_PREFIX_PATH}，Windows 平台默认为 C:/Program Files。
<name> 是你在 find_package(<name> REQUIRED) 命令中指定的包名。
<arch> 是系统的架构名。
```

**3. Unix搜索路径**

```
<prefix>/(lib/<arch>|lib*|share)/cmake/<name>*/
<prefix>/(lib/<arch>|lib*|share)/<name>*/
<prefix>/(lib/<arch>|lib*|share)/<name>*/cmake/
<prefix>/<name>*/(lib/<arch>|lib*|share)/cmake/<name>*/
<prefix>/<name>*/(lib/<arch>|lib*|share)/<name>*/
<prefix>/<name>*/(lib/<arch>|lib*|share)/<name>*/cmake/

# 说明
<prefix> 是变量 ${CMAKE_PREFIX_PATH}，Unix 平台默认为 /usr。
<name> 是你在 find_package(<name> REQUIRED) 命令中指定的包名。
<arch> 是系统的架构，例如 x86_64-linux-gnu 或 i386-linux-gnu。
（用于伺候 Ubuntu 喜欢把库文件套娃在 /usr/lib/x86_64-linux-gnu 目录下）
```

**4. 非标准安装路径**

非约定的路径，`find_package` 找不到第三方程序配置文件，如

- windows 下，安装到了 `D:`等盘下
- Unix 下，安装到了 `/opt` 目录下等等操作

这时候，需要手动指定一个变量，告诉 CMake 第三方程序及其配置文件在哪里 ！

**5. 使用**

```
find_package(XXX REQUIRED COMPONENTS xxx)
target_link_libraries(yourapp XXX::xxx)
```