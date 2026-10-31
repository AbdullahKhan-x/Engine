# CMakeLists.txt
add_executable(TextureDemo main.cpp)
target_link_libraries(TextureDemo Engine)
add_custom_command(TARGET TextureDemo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:TextureDemo>/assets
)
