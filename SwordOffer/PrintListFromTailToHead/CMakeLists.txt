# These commands are needed by modern versions of CMake:
CMAKE_MINIMUM_REQUIRED(VERSION 2.4)

# ---------------------------------------
# Declare a new CMake Project:
# ---------------------------------------
PROJECT(Test)

#aux_source_directory(. DIR_SRCS)

# ---------------------------------------------
# TARGET:
# ---------------------------------------------
# Define the executable targe
#add_executable(Test ${DIR_SRCS})

ADD_EXECUTABLE(Test 
			   main.cpp
			   src/PrintListFromTailToHead.cpp
			   include/PrintListFromTailToHead.h
)