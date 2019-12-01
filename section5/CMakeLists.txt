# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(targets)

# 设置项目名
set(TARGETS "targets")

# 子目录
set(SUBDIRS "src" "main")

# 头文件目录
set(INCDIRS "inc/power/")

# 库名字
set(LIBNAMES "power")

# 指定编译器
set(CMAKE_C_COMPILER "gcc")

# 显示指定使用的C++编译器
set(CMAKE_CXX_COMPILER "clang++" )         

#判断编译器类型,如果是gcc编译器,则在编译选项中加入c++11支持
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11")             # c++11
    set(CMAKE_CXX_FLAGS "-g")                     # 调试信息
    set(CMAKE_CXX_FLAGS "-Wall")                  # 开启所有警告
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")              # 调试包不优化
    set(CMAKE_CXX_FLAGS_RELEASE "-O1 -DNDEBUG ")  # release包优化
endif(CMAKE_COMPILER_IS_GNUCXX)

#指定编译类型
SET(CMAKE_BUILE_TYPE "RELEASE")

#工程的根目录
set(PROJECT_ROOT_PATH "${PROJECT_SOURCE_DIR}")
# 静态库生成后存放的目录
set(LIBRARY_OUTPUT_PATH "${PROJECT_ROOT_PATH}/cmake/lib/")
# 可执行生成后存放的目录
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_ROOT_PATH}/cmake/bin/")

# 头文件目录
foreach(incdir ${INCDIRS})
    # 添加头文件目录
    include_directories(${incdir})
endforeach()

# 子目录
foreach(subdir ${SUBDIRS})
    # 添加子目录
    add_subdirectory(${PROJECT_ROOT_PATH}/${subdir})
endforeach()

#告诉CMake静态库在哪里
link_directories(${LIBRARY_OUTPUT_PATH})
