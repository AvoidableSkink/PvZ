cmake_minimum_required(VERSION 3.8)
project(MPI)

set(HEADER_FILES
GameModel.h
Zombie.h
ZombieController.h
Board.hpp
BoardRow.hpp
PlantBullet.hpp
Plant.hpp
PeaShooter.hpp)

set(SOURCE_FILES
GameModel.cpp
Zombie.cpp
ZombieController.cpp
PlantBullet.cpp
Plant.cpp
Board.cpp
BoardRow.cpp
PeaShooter.cpp
main.cpp)

add_executable(PvZ main.cpp ${HEADER_FILES} ${SOURCE_FILES})

# Require MPI for this project:
find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})
include_directories(MPI_INCLUDE_PATH)
set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
target_link_libraries(PvZ ${MPI_LIBRARIES})

#to run this the program built with this 
# mpirun -n 4 ./PvZ
