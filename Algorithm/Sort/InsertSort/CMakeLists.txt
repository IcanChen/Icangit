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
			   src/InsertSort.cpp
			   include/InsertSort.h
)
