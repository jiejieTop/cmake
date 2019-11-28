# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_LIB_SRCS 变量
file(GLOB_RECURSE DIR_LIB_SRCS *.c)
file(GLOB_RECURSE DIR_LIB_HDRS *.h)

# 正则表达式得到当前目录名字作为提供给上一层的库名字
string(REGEX REPLACE ".*/(.*)" "\\1" LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR}) 

# 生成链接库
add_library(${LIB_NAME} ${DIR_LIB_SRCS} ${DIR_LIB_HDRS})

