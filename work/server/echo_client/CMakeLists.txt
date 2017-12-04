INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(../servercommon)

FILE(GLOB_RECURSE SRC_FILES "*.cpp")
FILE(GLOB_RECURSE COMMON_FILES "../servercommon/*.cpp")

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
ADD_EXECUTABLE(echo_client_${CMAKE_BUILD_TYPE} ${SRC_FILES} ${COMMON_FILES})

TARGET_LINK_LIBRARIES(echo_client_${CMAKE_BUILD_TYPE} pthread rt libconfig.so libnetwork.so librmi.so liblog.so libgameserver.a libutility.a libbasicnetwork.a libcommon.a)
