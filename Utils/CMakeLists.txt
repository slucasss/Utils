add_library(Utils STATIC 
src/Utils.cpp 
include/Utils.h
)

target_include_directories(Utils PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Utils PUBLIC
Debug
Maths
)