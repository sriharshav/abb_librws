cmake_minimum_required(VERSION 2.8.12)
project(abb_librws)

set(CMAKE_CXX_STANDARD 11)

########################
## POCO C++ Libraries ##
########################
# we need at least 1.4.3 because of websocket support
find_package(Poco 1.4.3 REQUIRED COMPONENTS Net Util Foundation XML)

###########
## Build ##
###########
set(SRC_FILES
    src/rws_client.cpp
    src/rws_common.cpp
    src/rws_interface.cpp
    src/rws_poco_client.cpp
    src/rws_rapid.cpp
    src/rws_simple_state_machine_interface.cpp)

include_directories(include
                    ${Poco_INCLUDE_DIRS}
                    ${catkin_INCLUDE_DIRS})

add_library(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${Poco_LIBRARIES})

add_subdirectory("examples")