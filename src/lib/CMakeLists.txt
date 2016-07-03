include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include")


set(files
    ByteCode.cpp
    ExecutionContext.cpp
    Process.cpp
    RegisterBank.cpp
    VM.cpp
    IRCodification.cpp
)

add_definitions( -std=c++11 -g)
add_library(VM STATIC ${files})