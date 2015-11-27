# These commands are needed by modern versions of CMake:
CMAKE_MINIMUM_REQUIRED(VERSION 2.4)

# ---------------------------------------
# Declare a new CMake Project:
# ---------------------------------------
PROJECT(ping)

#aux_source_directory(. DIR_SRCS)

# ---------------------------------------------
# TARGET:
# ---------------------------------------------
# Define the executable targe
#add_executable(ping ${DIR_SRCS})

ADD_EXECUTABLE(ping 
			   main.cpp
			   src/Ping.cpp
			   include/Ping.h
			   include/PingStruct.h
)
# Add the required libraries for linking:
TARGET_LINK_LIBRARIES(ping pthread)