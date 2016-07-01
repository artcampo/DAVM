include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include")

target_link_libraries(test1 lib)
add_executable(test1 test1.cpp)