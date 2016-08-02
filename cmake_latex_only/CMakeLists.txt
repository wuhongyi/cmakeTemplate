## CMakeLists.txt --- 
## 
## Description: 
## Author: Hongyi Wu(吴鸿毅)
## Email: wuhongyi@qq.com 
## Created: 日 7月 31 14:10:57 2016 (+0800)
## Last-Updated: 日 7月 31 14:56:07 2016 (+0800)
##           By: Hongyi Wu(吴鸿毅)
##     Update #: 13
## URL: http://wuhongyi.github.io 

cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

set(PROJ_NAME wu)
project(${PROJ_NAME})

# additional packages to be searched for by cmake
#list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

include(${PROJECT_SOURCE_DIR}/cmake/UseLATEX.cmake)

#----------------------------------------------------------------------------

# Note that normally CMakeLists.txt would not be considered an
# input to the document, but in this special case of documenting
# UseLATEX.cmake the contents of this file is actually included
# in the document.
ADD_LATEX_DOCUMENT(
  UseLATEX.tex
  INPUTS CMakeLists.txt     #INPUT是相关的文件，必须有
  # BIBFILES references.bib
  # USE_GLOSSARY
  # IMAGE_DIRS images
  # DEFAULT_PDF
  )

#----------------------------------------------------------------------------
## 以下测试内容

## LaTeX target to compile the PDF 
# option(BUILD_LATEX_PDF "Generate user's manual as PDF? (requires LaTeX)?" OFF)
# IF(BUILD_LATEX_PDF)
#   add_subdirectory(doc/manual)
# ENDIF()


######################################################################
