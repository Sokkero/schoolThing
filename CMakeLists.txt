cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "StateShowcase")

project(${PROJECT_NAME})

FILE(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} main.cpp)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
