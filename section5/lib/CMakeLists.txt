# 子目录
# set(SUBDIRS power)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 正则表达式得到当前目录名字作为提供给上一层的库名字
string(REGEX REPLACE ".*/(.*)" "\\1" LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR}) 

if (!${DIR_SRCS})
    # 生成链接库
    add_library(${LIB_NAME} ${DIR_SRCS})
endif()

# # 子目录
# foreach(subdir ${SUBDIRS})
#     # 找到子目录下的头文件
#     include_directories(${subdir})
#     # 添加子目录
#     add_subdirectory(${subdir})
# endforeach()