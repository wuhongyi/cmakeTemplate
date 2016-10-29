#CMakeLists.txt --- 
# 
# Description: CMake编译、运行程序模板。
# Author: Hongyi Wu(吴鸿毅)
# Email: wuhongyi@qq.com 
# Created: 六 2月 22 19:39:08 2014 (+0800)
# Last-Updated: 五 6月 13 13:27:14 2014 (+0800)
#           By: Hongyi Wu(吴鸿毅)
#     Update #: 58
# URL: http://wuhongyi.cn 

#cmake编译、运行程序模板！
#使用方法：将所有点hh文件放置到include文件夹，点cc文件放置到src，动态、静态链接库放置到lib
#将主函数放在与本CMakeLists.txt并列的目录中。
#在当前目录打开终端，输入        cmake .[Enter]   make
#或在build目录下打开终端，输入cmake ..[Enter]   make
#----------------------------------------------------------------------------
#判断cmake版本是否符合，对工程命名
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
set(CMAKE_C_COMPILER "/usr/local/bin/gcc")  #调用gcc4.8.1，原本默认4.4.6
set(CMAKE_CXX_COMPILER "/usr/local/bin/g++") #调用g++4.8.1，原本默认4.4.6
set(PROJ_NAME wu)
project(${PROJ_NAME})
set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated") #支持最新c++11
#c++0x是新的C++意思。而-Wno-deprecated是表示 no-deprecated这类警告忽略。

##解释：
##cmake_minimum_required(VERSION 2.8 FATAL_ERROR) 这是最低版本要求设置，我电脑cmake安装2.8的版本，所以可以写2.8，一般SL默认安装2.6的，所以必须将数设置小于或等于2.6！！！
##set(CMAKE_C_COMPILER "/usr/local/bin/gcc")  cmake会使用默认的c编译器。这是指定编译器，不知道怎么用的把它注释掉！！！cmake安装之后对编译器升级过或想使用更高版本的，就自己给它指出来。
##set(CMAKE_CXX_COMPILER "/usr/local/bin/g++") cmake会使用默认的c++编译器。这是指定编译器，！！！cmake安装之后对编译器升级过或想使用更高版本的，就自己给它指出来。
##set(PROJ_NAME wu) 把wu改成你想要的工程名字，按照下面的设置，wu会是可执行文件的名字
##project(${PROJ_NAME}) 设置工程名称，这个不需要改动。
##set(CMAKE_CXX_FLAGS "-std=c++11 -Wno-deprecated") 不知道怎么用的把它注释掉！！！这是使用最新的11年的c++国际标准，要使用全部的功能需要g++4.8.1即以上。

#----------------------------------------------------------------------------
#指出所需hh，cc，so，a文件位置路径，并用变量命名
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.c*)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*h)
file(GLOB libs ${PROJECT_SOURCE_DIR}/lib/*)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) #生成可执行文件放在bin文件夹中

##解释：
##这里不需要改动懒得解释，这个自己研究！！！

#----------------------------------------------------------------------------
#add_executable()后面的是一个参数列表，可带多个要编译的文件名，中间以空格或回车等隔开。生成一个可执行文件
add_executable(${PROJ_NAME} writedata.cpp ${sources} ${headers})
#链接库，后面补上名称
target_link_libraries(${PROJ_NAME} ${libs} /usr/lib64/libhdf5.so /usr/lib64/libhdf5_cpp.so /usr/lib64/libhdf5.so.7 /usr/lib64/libhdf5_cpp.so.7 /usr/lib64/libhdf5_hl.so  /usr/lib64/libhdf5_hl.so.7 /usr/lib64/libhdf5_hl_cpp.so /usr/lib64/libhdf5_hl_cpp.so.7)

##解释：
##add_executable(${PROJ_NAME} input.cc ${sources} ${headers}) 将input.cc换成你的主函数名就可以了
##target_link_libraries(${PROJ_NAME} ${libs} ) 这个是链接链接库，不需要改。

#----------------------------------------------------------------------------
#将所需数据文件复制到bin文件夹
#set(CopyFile
#    data1.dat data2.dat
#  )

#foreach(copyfile ${CopyFile})
#  configure_file(
#    ${PROJECT_SOURCE_DIR}/${copyfile}
#    ${PROJECT_SOURCE_DIR}/bin/${copyfile}
#    COPYONLY
#    )
#endforeach()

##解释：
##如果程序运行需要从文本读取数据，我们的可执行文件放置在bin文件夹，那么我们就需要将原本放在主目录的数据文件复制到bin文件夹中。
##将data1.dat data2.dat改成自己要复制的文件名称就可以。如果不需要复制数据文件就把此功能注释。
###################################
