include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../include")


set(files
    ByteCode.cpp
    ExecutionContext.cpp
    Process.cpp
    RegisterBank.cpp
    VM.cpp
)

add_library(lib STATIC ${files})