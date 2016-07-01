include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include")

add_definitions( -std=c++11 )


add_executable(test1 test1.cpp)
target_link_libraries(test1 VM)

INSTALL(TARGETS test1 DESTINATION bin)