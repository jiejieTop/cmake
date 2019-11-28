# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(targets)

# 设置可执行文件目标
set(TARGETS targets)

# 子目录
set(SUBDIRS power)

# 指定编译器
set(CMAKE_C_COMPILER "gcc")

#判断编译器类型,如果是gcc编译器,则在编译选项中加入c++11支持
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif(CMAKE_COMPILER_IS_GNUCXX)

#指定编译类型
SET(CMAKE_BUILE_TYPE "RELEASE")

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 打印变量
# message(${DIR_SRCS})

# 指定生成目标
add_executable(${TARGETS} ${DIR_SRCS})

# 添加子目录
foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()

# 添加链接库
target_link_libraries(${TARGETS} ${SUBDIRS})
