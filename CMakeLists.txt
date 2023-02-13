cmake_minimum_required(VERSION 3.22)
project(option)

add_subdirectory(protos)
add_subdirectory(src)

include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/protos)
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cc)
target_link_libraries(${PROJECT_NAME} Options)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
