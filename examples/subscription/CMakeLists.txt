# Root CMake include examples. Build from root
project(example_subscription)

set(SRC_FILES
    subscription.cpp)

include_directories(include
                    ../../include/abb_librws)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} abb_librws ${Poco_LIBRARIES})
