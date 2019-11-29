# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(targets)

# 设置可执行文件文件名
set(TARGETS targets)

# 设置可执行文件的输出目录
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)     

# 子目录
set(SUBDIRS lib)

# 指定库目录
# set(CMAKE_PREFIX_PATH lib/)
set(LIBDIRS power)

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
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG ")  # release包优化
endif(CMAKE_COMPILER_IS_GNUCXX)

#指定编译类型
SET(CMAKE_BUILE_TYPE "RELEASE")

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 打印变量
# message(${DIR_SRCS})

# 编译为可执行文件
add_executable(${TARGETS} ${DIR_SRCS})

# 子目录
foreach(subdir ${SUBDIRS})
    # 找到子目录下的头文件
    include_directories(${subdir})
    # 添加子目录
    add_subdirectory(${subdir})
endforeach()

# 库文件
foreach(libdir ${LIBDIRS})
    # 找到库文件目录
    link_directories(${libdir})

    # 找到库的头文件
    include_directories(${libdir})

    # 添加链接库
endforeach()

target_link_libraries(${TARGETS} ${LIBDIRS})

# -------------------------------------------------------------------------------------------------------------------

#add_executable(project1 ${src})                        #编译为可执行程序
#add_library(project1 ${src})                           #编译为静态库
#add_library(project1 SHARED ${src})                    #编译为动态链接库

#add_executable(project1 MACOSX_BUNDLE ${src})          #编译为可执行程序 *.app

#add_library(project1 MODULE ${src})                    #编译为程序资源包 *.bundle
#set_target_properties(project1 PROPERTIES BUNDLE TRUE)

#add_library(project1 SHARED ${src})                     #编译为程序资源包 *.framework
#set_target_properties(project1 PROPERTIES FRAMEWORK TRUE)

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../bin)       #设置可执行文件的输出目录

#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib)           #设置库文件的输出目录