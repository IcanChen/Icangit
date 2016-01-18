# These commands are needed by modern versions of CMake:
CMAKE_MINIMUM_REQUIRED(VERSION 2.4)

# ---------------------------------------
# Declare a new CMake Project:
# ---------------------------------------
PROJECT(Test)

#set(CMAKE_BUILD_TYPE "Debug")

#aux_source_directory(. DIR_SRCS)

# ---------------------------------------------
# TARGET:
# ---------------------------------------------
# Define the executable targe
#add_executable(Test ${DIR_SRCS})

ADD_EXECUTABLE(Test 
			   main.cpp
			   src/UdpEchoClient.cpp
			   src/base/CError.cpp
			   src/base/SockWraps.cpp
			   src/base/UnixWraps.cpp
			   src/base/StdioWraps.cpp
			   
			   include/base/CError.h
			   include/base/NetworkGrobleDefine.h
			   include/base/SockWraps.h
			   include/base/UnixWraps.h
			   include/base/StdioWraps.h
			   include/UdpEchoClient.h
)
