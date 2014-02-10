cmake_minimum_required(VERSION 2.8)

project(matopsmpi)

set(SOURCES matops_mpi.c matrix.c)
add_executable(matopsmpi ${SOURCES})

# Require MPI for this project:
find_package(MPI REQUIRED)
set(CMAKE_C_COMPILE_FLAGS ${CMAKE_C_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_C_LINK_FLAGS ${CMAKE_C_LINK_FLAGS} ${MPI_LINK_FLAGS})
include_directories(MPI_INCLUDE_PATH)
target_link_libraries(matopsmpi ${MPI_LIBRARIES})
