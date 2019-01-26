# Root CMake include examples. Build from root
project(example_static_runtime_info)

set(SRC_FILES
    static_runtime_info.cpp)

include_directories(include
                    ../../include/abb_librws)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} abb_librws ${Poco_LIBRARIES})
