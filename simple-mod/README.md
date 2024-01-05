
# 多模块工程

CMake 多模块工程，这是一个示例工程

- simple-mod , 项目名称
- demo         , 主模块 main  ，引用 store 模块时，需配置依赖
- store        , 子模块 store 

## 目录结构

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

