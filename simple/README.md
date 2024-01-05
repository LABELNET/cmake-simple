
# 单模块工程

CMake 单模块工程，这是一个示例工程

- simple   , 项目名称
- cmake    , 第三方依赖
- demo     , 主模块 main

## 目录结构

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

