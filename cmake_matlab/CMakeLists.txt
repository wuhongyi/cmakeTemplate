##CMakeLists.txt --- 
## 
## Description: 
## Author: Hongyi Wu(吴鸿毅)
## Email: wuhongyi@qq.com 
## Created: 五 8月 15 06:33:03 2014 (-0400)
## Last-Updated: 三 12月 10 15:59:57 2014 (+0800)
##           By: Hongyi Wu(吴鸿毅)
##     Update #: 15
## URL: http://wuhongyi.cn 

#cmake编译、运行程序模板！
#使用方法：将所有点hh文件放置到include文件夹，点cc文件放置到src
#在当前目录打开终端，输入        cmake .         make
#或在新建build目录下打开终端，输入cmake ..        make
#----------------------------------------------------------------------------
#判断cmake版本是否符合，对工程命名
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
#set(CMAKE_C_COMPILER "/usr/local/bin/gcc")  #调用gcc4.8.1，原本默认4.4.6
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++") #调用g++4.8.1，原本默认4.4.6
set(PROJ_NAME wu)
project(${PROJ_NAME})
#set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated") #支持最新c++11
#c++0x是新的C++意思。而-Wno-deprecated是表示 no-deprecated这类警告忽略。
SET(CMAKE_BUILD_TYPE Debug) 
#----------------------------------------------------------------------------
#指出所需hh，cc，so，a文件位置路径，并用变量命名
include_directories(${PROJECT_SOURCE_DIR}/include
                      /usr/local/MATLAB/R2012a/extern/include )
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh /usr/local/MATLAB/R2012a/extern/include/*)
file(GLOB libs ${PROJECT_SOURCE_DIR}/lib/*)
#----------------------------------------------------------------------------
#add_executable()后面的是一个参数列表，可带多个要编译的文件名，中间以空格或回车等隔开。生成一个可执行文件
add_executable(${PROJ_NAME} main.cc ${sources} ${headers})

target_link_libraries(${PROJ_NAME} ${libs} 
    -L/usr/local/MATLAB/R2012a/bin/glnxa64 eng mat mex ut mx -Wl,-rpath=/usr/local/MATLAB/R2012a/bin/glnxa64
)

#-L/usr/local/MATLAB/R2012a/bin/glnxa64 eng mat mex ut mx
#-L/home/wuhongyi/root/lib Core Cint RIO Net Hist Graf Graf3d Gpad Tree Rint Postscript Matrix Physics MathCore Thread  -pthread  m dl -rdynamic 



######################################################################
