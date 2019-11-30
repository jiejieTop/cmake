# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 编译为可执行文件
add_executable(${TARGETS} ${DIR_SRCS})

# 告诉CMake静态库在哪里
foreach(libname ${LIBNAMES})

    # 搜索库
    find_library(
        libraries
        NAMES ${libname}
        PATHS ${LIBRARY_OUTPUT_PATH}
    )

    # 添加链接库
    target_link_libraries(${TARGETS} ${libraries})
endforeach()

