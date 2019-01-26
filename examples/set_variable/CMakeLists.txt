# Root CMake include examples. Build from root
project(example_set_variable)

set(SRC_FILES
    set_variable.cpp)

include_directories(include
                    ../../include/abb_librws)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} abb_librws ${Poco_LIBRARIES})
