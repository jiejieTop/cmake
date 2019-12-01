# 子目录
set(SUBDIRS "power")

# 子目录
foreach(subdir ${SUBDIRS})
    # 添加子目录
    add_subdirectory(${subdir})
endforeach()



