add_library(Debug OBJECT 
src/Debug.cpp 
include/Debug.h
)

target_include_directories(Debug PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)