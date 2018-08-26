cmake_minimum_required(VERSION 2.8.12)
project(abb_librws)

option(WITH_ROS "Build with ROS" ON)

set(CMAKE_CXX_STANDARD 11)

if (WITH_ROS)
        find_package(catkin REQUIRED COMPONENTS cmake_modules)
endif()

########################
## POCO C++ Libraries ##
########################
# we need at least 1.4.3 because of websocket support
find_package(Poco 1.4.3 REQUIRED COMPONENTS Net Util Foundation XML)

if (WITH_ROS)
        ###################################
        ## catkin specific configuration ##
        ###################################
        catkin_package(INCLUDE_DIRS include
                LIBRARIES ${PROJECT_NAME}
                DEPENDS Poco)
endif()

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

if (WITH_ROS)
        include_directories(include
                        ${Poco_INCLUDE_DIRS}
                        ${catkin_INCLUDE_DIRS})
else()
        include_directories(include
                        ${Poco_INCLUDE_DIRS})
endif()

add_library(${PROJECT_NAME} ${SRC_FILES})
if (WITH_ROS)
        target_link_libraries(${PROJECT_NAME} ${Poco_LIBRARIES} ${catkin_LIBRARIES})
else()
        target_link_libraries(${PROJECT_NAME} ${Poco_LIBRARIES})
endif()

if (WITH_ROS)
        #############
        ## Install ##
        #############
        install(TARGETS ${PROJECT_NAME}
                LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})

        install(DIRECTORY include
                DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
                FILES_MATCHING PATTERN "*.h")
endif()