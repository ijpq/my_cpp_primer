cmake_minimum_required(VERSION 3.15)
project(hasptr)
# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
#INCLUDE_DIRECTORIES(HasPtr.h)
# 指定生成目标
set(CMAKE_CXX_STANDARD 11)
add_executable(HasPtr HasPtr.cpp)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")