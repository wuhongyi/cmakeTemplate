#CMakeLists.txt --- 
# 
# Description: CMake编译、运行程序模板。
# Author: Hongyi Wu(吴鸿毅)
# Email: wuhongyi@qq.com 
# Created: 六 2月 22 19:39:08 2014 (+0800)
# Last-Updated: 二 8月 16 17:01:44 2016 (+0800)
#           By: Hongyi Wu(吴鸿毅)
#     Update #: 79
# URL: http://wuhongyi.cn 

#cmake编译、运行程序模板！
#使用方法：将所有点hh文件放置到include文件夹，点cc文件放置到src，动态、静态链接库放置到lib
#将主函数放在与本CMakeLists.txt并列的目录中。
#在当前目录打开终端，输入        cmake .[Enter]   make
#或在build目录下打开终端，输入cmake ..[Enter]   make
#编译调试版本 cmake -DCMAKE_BUILD_TYPE=Debug ..
#----------------------------------------------------------------------------
#判断cmake版本是否符合，对工程命名
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

list( APPEND CMAKE_CXX_FLAGS "-fPIC -O2" )
list( APPEND CMAKE_LD_FLAGS "-fPIC -O2" )
# additional packages to be searched for by cmake
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

#Compile with C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if (CMAKE_COMPILER_IS_GNUCXX)
	if (${CMAKE_CXX_COMPILER_VERSION} VERSION_GREATER "4.9")
		#Make compiler messages nice with colored tags.
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=auto")
	endif()

	if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
	   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
	endif()
	
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
endif()

#set(CMAKE_C_COMPILER "/usr/local/bin/gcc")  #调用gcc4.8.1，原本默认4.4.6
#set(CMAKE_CXX_COMPILER "/usr/local/bin/g++") #调用g++4.8.1，原本默认4.4.6
#enable_language(Fortran)
set(PROJ_NAME wu)
project(${PROJ_NAME})
# project version
set( ${PROJECT_NAME}_VERSION_MAJOR 1 )
set( ${PROJECT_NAME}_VERSION_MINOR 1 )
set( ${PROJECT_NAME}_VERSION_PATCH 1 )

SET(CMAKE_BUILD_TYPE Debug) #编译调试版本

ADD_DEFINITIONS(
 -O3 -W -Wall
 -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-deprecated -Wwrite-strings
 -D__WUR= -D_FILE_OFFSET_BITS=64 
)

#----------------------------------------------------------------------------

FIND_PACKAGE( OpenMP REQUIRED)  #OpenMP并行
if(OPENMP_FOUND)  
message("-- Found OpenMP")  
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")  
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")  
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")  
endif() 

#----------------------------------------------------------------------------

#指出所需hh，cc，so，a文件位置路径，并用变量命名
include_directories(${PROJECT_SOURCE_DIR}/include  )
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)
file(GLOB libs ${PROJECT_SOURCE_DIR}/lib/*)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) #生成可执行文件放在bin文件夹中

#----------------------------------------------------------------------------

#add_executable()后面的是一个参数列表，可带多个要编译的文件名，中间以空格或回车等隔开。生成一个可执行文件
add_executable(${PROJ_NAME} input.cc ${sources} ${headers})
#链接库，后面补上名称
target_link_libraries(${PROJ_NAME} ${libs} -pthread  m dl -rdynamic )

#----------------------------------------------------------------------------

#将所需数据文件复制到bin文件夹
set(CopyFile
    data1.dat data2.dat
  )

foreach(copyfile ${CopyFile})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${copyfile}
    ${PROJECT_SOURCE_DIR}/bin/${copyfile}
    COPYONLY
    )
endforeach()

###################################
