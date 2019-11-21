cmake_minimum_required(VERSION 3.10)
project(Parser)

set(CMAKE_CXX_STANDARD 11)
# 编译google test，会在当前目录生成libtest.a动态库
add_subdirectory(./googletest)
# 将用于google test的头文件gtest.h添加到include路径中
include_directories(./googletest/include)
# 将libtest.a添加到链接路径中（同时需要添加googletest运行需要的pthread）
set(LIBRARIES
        gtest
        pthread)
add_executable(Parser  user_interface.h build_in.h build_in.cpp parser.h parser.cpp user_type.h user_type.cpp main.cpp)

target_link_libraries(Parser ${LIBRARIES})
