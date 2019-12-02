# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 编译为可执行文件
add_executable(${TARGETS} ${DIR_SRCS})

# 告诉CMake静态库在哪里
foreach(findlib ${LIBNAMES})

    # # 搜索库,其实不需要搜索，直接在add后link即可
    # find_library(
    #     libraries
    #     NAMES ${findlib}
    #     PATHS ${LIBRARY_OUTPUT_PATH}
    #     NO_DEFAULT_PATH     #通过多次调用find_library命令以及NO_*选项，可以覆盖工程的这个默认顺序
    # )

    # message(STATUS "find library is ${libraries}")
    # 添加链接库
    target_link_libraries(${TARGETS} ${findlib})
endforeach()

