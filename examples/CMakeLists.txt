cmake_minimum_required(VERSION 2.8.12)
project(abb_librws_example)

set(CMAKE_CXX_STANDARD 11)

find_package(Poco 1.4.3 REQUIRED COMPONENTS Net Util Foundation XML)

set(SRC_FILES
    ex01.cpp)

include_directories(include
                    ../include/abb_librws/
                    ${Poco_INCLUDE_DIRS})

link_directories(../build)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} abb_librws ${Poco_LIBRARIES})
