#CMakeLists.txt --- 
# 
# Description: CMake生成动态、静态链接库模板。
# Author: Hongyi Wu(吴鸿毅)
# Email: wuhongyi@qq.com 
# Created: 六 2月 22 19:39:08 2014 (+0800)
# Last-Updated: 三 12月 10 16:01:15 2014 (+0800)
#           By: Hongyi Wu(吴鸿毅)
#     Update #: 9
# URL: http://wuhongyi.cn 

#cmake
#使用方法：将所有点hh文件放置到include文件夹，点cc文件放置到src
#在当前目录打开终端，输入        cmake .         make
#或在新建build目录下打开终端，输入cmake ..        make
#----------------------------------------------------------------------------
#判断cmake版本是否符合，对工程命名
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_C_COMPILER "/usr/local/bin/gcc")  #调用gcc4.8.1，原本默认4.4.6
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++") #调用g++4.8.1，原本默认4.4.6
set(PROJ_NAME wu)
project(${PROJ_NAME})
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated") #支持最新c++11
#c++0x是新的C++意思。而-Wno-deprecated是表示 no-deprecated这类警告忽略。
#SET(CMAKE_BUILD_TYPE Debug) #编译调试版本 
#----------------------------------------------------------------------------
#指出所需hh，cc文件位置路径，并用变量命名
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
#生成动态、静态链接库，SHARED表示动态链接库，STATIC表示静态库。
ADD_LIBRARY(date1 SHARED ${sources} ${headers})







###################################
