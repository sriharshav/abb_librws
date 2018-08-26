# Root CMake include examples. Build from root
project(abb_librws_example)

set(SRC_FILES
    ex01.cpp)

include_directories(include
                    ../include/abb_librws)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} abb_librws ${Poco_LIBRARIES})
