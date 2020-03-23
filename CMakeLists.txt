cmake_minimum_required(VERSION 3.8)
project(MPI)

set(HEADER_FILES
board.hpp
peaShooter.hpp)

set(SOURCE_FILES
board.cpp
peaShooter.cpp)

add_executable(PvZ main.cpp ${HEADER_FILES} ${SOURCE_FILES})

# Require MPI for this project:
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
include_directories(MPI_INCLUDE_PATH)
set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
target_link_libraries(conwaysGame ${MPI_LIBRARIES})

#to run this the program built with this 
# mpirun -n 4 conwaysGame
