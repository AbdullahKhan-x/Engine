add_executable(
	AnimationDemo # executable
	main.cpp
)

target_link_libraries(AnimationDemo Engine)

add_custom_command(TARGET AnimationDemo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/assets
	$<TARGET_FILE_DIR:AnimationDemo>/assets
)
