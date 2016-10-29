## CMakeLists.txt --- 
## 
## Description: 
## Author: Hongyi Wu(吴鸿毅)
## Email: wuhongyi@qq.com 
## Created: 日 7月 31 14:10:57 2016 (+0800)
## Last-Updated: 一 8月  1 13:21:09 2016 (+0800)
##           By: Hongyi Wu(吴鸿毅)
##     Update #: 24
## URL: http://wuhongyi.cn 

cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

# set(PROJ_NAME wu)
# project(${PROJ_NAME})

# additional packages to be searched for by cmake
#list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

find_package(LATEX COMPONENTS XELATEX)

#----------------------------------------------------------------------------

## 还有问题，没法将文件夹复制到build文件夹
set(name prc)

set(CopyFile
    ${name}.tex reference.bib
  )

foreach(copyfile ${CopyFile})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${copyfile}
    ${CMAKE_CURRENT_BINARY_DIR}
    COPYONLY
    )
endforeach()


if(NOT LATEX_XELATEX_FOUND)
  message("xelatex not found... ")
else()
  add_custom_command (
    OUTPUT ${name}.pdf
    COMMAND ${XELATEX_COMPILER} ${name}.tex
    COMMAND ${BIBTEX_COMPILER} ${name}
    COMMAND ${PDFLATEX_COMPILER} ${name}.tex
    COMMAND ${PDFLATEX_COMPILER} ${name}.tex
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${name}.tex
    )
endif()



add_custom_target(${name} ALL DEPENDS ${name}.pdf)



######################################################################
