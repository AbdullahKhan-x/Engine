add_library(
	Engine STATIC

	src/engine.cpp
)

target_include_directories(
	Engine PUBLIC include
)

