# CMakeList模板

**工程目录**

```
cmake_minimum_required(VERSION 2.0)

PROJECT(PROJ)

SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -Wall -D_DEBUG -fpermissive -std=c++11")
SET(CMAKE_CXX_FLAGS_RELEASE "-O0 -g -Wall -fpermissive -std=c++11")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

ADD_SUBDIRECTORY(program)
```

**项目目录**

```
INCLUDE_DIRECTORIES(.)

FILE(GLOB_RECURSE SRC_FILES "*.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
ADD_EXECUTABLE(program_${BUILD_TYPE} ${SRC_FILES})

TARGET_LINK_LIBRARIES(program_${BUILD_TYPE} pthread rt)
```

# 一个build脚本模板

```
#! /bin/bash

mkdir -p tmp_build
cd tmp_build

cmake -DCMAKE_BUILD_TYPE=debug ..
time make -j8
```