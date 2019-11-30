# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 子目录
set(SUBDIRS "power")

# 子目录
foreach(subdir ${SUBDIRS})
    message(STATUS "add_subdirectory : " ${subdir})
    # 添加子目录
    add_subdirectory(${subdir})
endforeach()



