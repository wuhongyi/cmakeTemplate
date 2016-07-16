#CMakeLists.txt --- 
# 
# Description: CMake调用root库！
# Author: Hongyi Wu(吴鸿毅)
# Email: wuhongyi@qq.com 
# Created: 六 2月 22 19:44:06 2014 (+0800)
# Last-Updated: 日 3月 27 20:31:49 2016 (+0800)
#           By: Hongyi Wu(吴鸿毅)
#     Update #: 46
# URL: http://wuhongyi.github.io 

#cmake编译、运行程序模板！
#使用方法：将所有点hh文件放置到include文件夹，点cc文件放置到src
#在当前目录打开终端，输入        cmake .         make
#或在新建build目录下打开终端，输入cmake ..        make
#----------------------------------------------------------------------------
#判断cmake版本是否符合，对工程命名
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#set(CMAKE_C_COMPILER "/usr/local/bin/gcc")  #调用gcc4.8.1，原本默认4.4.6
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++") #调用g++4.8.1，原本默认4.4.6
set(PROJ_NAME wu)
project(${PROJ_NAME})
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated") #支持最新c++11
#c++0x是新的C++意思。而-Wno-deprecated是表示 no-deprecated这类警告忽略。
SET(CMAKE_BUILD_TYPE Debug) 
#----------------------------------------------------------------------------
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
# Find ROOT (required package)
#
find_package(ROOT REQUIRED)
find_package( ROOT COMPONENTS ASImage EG FFTW FitPanel Ged Geom Gui GuiBld GuiHtml GX11 GX11TTF Hbook Hist Html MathMore Minuit Minuit2 MLP Proof RGL RooFit RooFitCore Smatrix Spectrum Table TMVA TreePlayer TreeViewer )#COMPONENTS可选 ，REQUIRED COMPONENTS必须有
#----------------------------------------------------------------------------
#指出所需hh，cc，so，a文件位置路径，并用变量命名
include_directories(${PROJECT_SOURCE_DIR}/include ${ROOT_INCLUDE_DIRS})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)
file(GLOB libs ${PROJECT_SOURCE_DIR}/lib/*)
#----------------------------------------------------------------------------
#add_executable()后面的是一个参数列表，可带多个要编译的文件名，中间以空格或回车等隔开。生成一个可执行文件
add_executable(${PROJ_NAME} mainGUI.cc ${sources} ${headers})

target_link_libraries(${PROJ_NAME} ${libs} ${ROOT_LIBRARIES} ${ROOT_COMPONENT_LIBRARIES} )


#-L/home/wuhongyi/root/lib Core Cint RIO Net Hist Graf Graf3d Gpad Tree Rint Postscript Matrix Physics MathCore Thread  -pthread  m dl -rdynamic 


#################################
