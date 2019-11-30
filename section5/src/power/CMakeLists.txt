# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 正则表达式得到当前目录名字作为提供给上一层的库名字
string(REGEX REPLACE ".*/(.*)" "\\1" LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR}) 

if (${DIR_SRCS})
    message(STATUS "aux_source_directory: ${DIR_SRCS}")
    # 匹配库名字
    foreach(libname ${LIBNAMES})
        message(STATUS "power ${DIR_SRCS} ${libname}")
        add_library(${libname} ${DIR_SRCS})
        if (${DIR_SRCS} == ${libname})
            # 生成链接库
            add_library(${libname} ${DIR_SRCS})
        endif()
    endforeach()
endif()

message(STATUS "${LIBNAMES}")
add_library(${LIB_NAME} ${DIR_SRCS})




