set(CORE_HEADERS 
include/Core.h
)

set(CORE_SOURCES 
src/Core.cpp
)

add_library(Core OBJECT 
${CORE_HEADERS}
${CORE_SOURCES}
)

target_include_directories(Core PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include 
)

