cmake_minimum_required(VERSION 3.7)
project(udemy_1_initial)
#warrning levels defines send to GCC
#add_definitions("-Wall" "-g")


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR})
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp ${PROJECT_SOURCE_DIR}/*.h)
add_executable(${PROJECT_NAME} ${SRC_FILES})







