cmake_minimum_required(VERSION 3.30)
project(AIZO_Project_1)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(AIZO_Project_1 main.cpp
        Algorythms.h
        GUI.h
        RaportGeneration.h)
