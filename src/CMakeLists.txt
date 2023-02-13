include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/protos)

add_library(Options Options.cc)

target_link_libraries(Options protos)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
