cmake_minimum_required(VERSION 3.10)

# set the project name
project(SimpleRestApp VERSION 2.0)

set(CPPRESTFLAGS "-lcpprest -lpthread -lboost_system -lssl -lcrypto")


add_library(Controller Controller.cpp)

# add the executable
add_executable(program main.cpp)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pedantic -Wall")

target_link_libraries(program PUBLIC Controller "${CPPRESTFLAGS}")

target_include_directories(program PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )



