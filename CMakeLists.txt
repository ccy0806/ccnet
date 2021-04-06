cmake_minimum_required(VERSION 2.8.3)										#Cmake最低版本号要求
project(ccnet)																#项目信息




set(CMAKE_BUILD_TYPE "Debug")												#设置编译模式

if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall -Wno-unused-variable -pthread")
else( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2 -pthread -fopenmp")
endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )


include_directories(${PROJECT_SOURCE_DIR})                                  #指定include路径，头文件寻址起点路径

										
add_library(${PROJECT_NAME} SHARED
src/base/Threadpool.cpp
)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)						#设置二进制可执行文件输出目录


#add_executable(Singleton_test src/test/Singleton_test.cpp)					#指定生成目标
#add_executable(Threadpool_test src/test/Threadpool_test.cpp src/base/Threadpool.cpp)
#add_executable(Noncopyable_test src/test/Noncopyable_test.cpp)
#add_executable(Timestamp_test src/test/Timestamp_test.cpp src/base/Timestamp.cpp)
#add_executable(Logger_test src/test/Logger_test.cpp src/base/Logger.cpp src/base/Timestamp.cpp)

#add_executable(stringstream_test src/test/stringstream_test.cpp  src/base/Timestamp.cpp)

#add_executable(FixBuffer_test src/test/FixBuffer_test.cpp)
add_executable(AsyncLog_test src/test/AsyncLog_test.cpp src/base/Logger.cpp src/base/Timestamp.cpp)
