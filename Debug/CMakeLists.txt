set(DEBUG_HEADERS
include/Debug.h
include/Assert.h
include/Profiler.h
)

set(DEBUG_SOURCES
src/Debug.cpp
src/Profiler.cpp
)

add_library(Debug OBJECT 
${DEBUG_HEADERS}
${DEBUG_SOURCES}
)

target_include_directories(Debug PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Debug PUBLIC
Core
)