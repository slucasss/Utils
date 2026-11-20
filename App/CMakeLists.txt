add_executable(App src/main.cpp)

target_link_libraries(App PRIVATE UtilsLib)

add_custom_command(TARGET App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:UtilsLib>
    $<TARGET_FILE_DIR:App>
)
