cmake_minimum_required(VERSION 2.0)

PROJECT(PROJ)

SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -Wall -D_DEBUG -fpermissive -std=c++11")
SET(CMAKE_CXX_FLAGS_RELEASE "-O0 -g -Wall -fpermissive -std=c++11")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib/linux)

ADD_SUBDIRECTORY(echo_server)
ADD_SUBDIRECTORY(echo_client)
