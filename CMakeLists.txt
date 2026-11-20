cmake_minimum_required(VERSION 3.20)

project (Utils VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Maths)
add_subdirectory(Debug)
add_subdirectory(Utils)
add_subdirectory(Core)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(UtilsLib SHARED
$<TARGET_OBJECTS:Core>
$<TARGET_OBJECTS:Maths>
$<TARGET_OBJECTS:Debug>
$<TARGET_OBJECTS:Utils>
)

target_link_libraries(UtilsLib PUBLIC
Core
Maths
Debug
Utils
)

add_subdirectory(App)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT App)







