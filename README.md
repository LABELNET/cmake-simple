CMake-工程结构示例

- Windows 环境 : mysys2 , 编译环境  ucrt64
- Mac 环境 : 推荐 Homebrew
- Linux 环境 : Bash 环境自行安装

名词说明

- 项目，开发的项目工程，以项目编译配置为主
- 模块，开发的功能模块，以代码实现功能为主

## 1. Simple

单项目单模块工程，适用于不复杂项目

```
$ .SIMPLE      
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

## 2. Simple-deps

单项目单模块工程 + 第三方依赖环境 ，在主模块中使用第三方库依赖，比如 opencv 

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

## 3. Simple-mod

单项目-多模块工程

```
$ SIMPLE-MOD      
│   CMakeLists.txt                 # 项目根 CMakeLists.txt,多模块
│   README.md                      # 说明文档，无关
├───.vscode                        # 头文件路径配置
│       c_cpp_properties.json
├───build                          # CMake 编译输出
├───cmake                          # 第三方依赖存放路径
├───demo                           # 主模块 main
│   │   CMakeLists.txt             # 主模块 CMakeLists.txt ，配置子模块链接
│   │
│   ├───include                    # 源码: 主模块头文件
│   │       demo_utils.h   
│   │  
│   └───src                        # 源码: 主模块源码实现
│           demo_utils.cc
│           main.cc                
│
└───store                          # 子模块
    │   CMakeLists.txt             # 子模块 CMakeLists.txt ，本地依赖包
    │
    ├───include                    # 源码: 子模块头文件
    │       store_utils.h
    │
    └───src                        # 源码: 子模块源码实现
            store_utils.cc
```

## 4.Simpel-mod-deps 

单项目多模块 + 第三方依赖 ， 在模块中使用第三方库依赖，比如 grpc


```
$ SIMPLE-MOD-DEPS      
│   CMakeLists.txt                 # 项目根 CMakeLists.txt,多模块
│   README.md                      # 说明文档，无关
├───.vscode                        # 头文件路径配置
│       c_cpp_properties.json
├───build                          # CMake 编译输出
├───cmake                          # 第三方依赖存放路径 FindXXX.cmake
├───demo                           # 主模块 main
│   │   CMakeLists.txt             # 主模块 CMakeLists.txt ，配置子模块链接
│   │
│   ├───include                    # 源码: 主模块头文件
│   │       demo_utils.h   
│   │  
│   └───src                        # 源码: 主模块源码实现
│           demo_utils.cc
│           main.cc                
│
└───store                          # 子模块
    │   CMakeLists.txt             # 子模块 CMakeLists.txt ，本地依赖包
    │
    ├───include                    # 源码: 子模块头文件
    │       store_utils.h
    │
    └───src                        # 源码: 子模块源码实现
            store_utils.cc
```
