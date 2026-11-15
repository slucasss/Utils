set(MATHS_HEADERS 
include/Maths.h 
include/Vector3.h 
include/Vector3.inl 
)

set(MATHS_SOURCES 
src/Vector3.cpp 
)

add_library(Maths OBJECT 
${MATHS_HEADERS}
${MATHS_SOURCES}
)

target_include_directories(Maths PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include 
)

