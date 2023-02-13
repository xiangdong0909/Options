project(protos)

add_library(${PROJECT_NAME} SOptions.pb.cc)

target_link_libraries(${PROJECT_NAME} protobuf)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
