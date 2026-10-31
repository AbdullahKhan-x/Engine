add_library(
	Engine STATIC
	src/Core/Engine.cpp
	src/Graphics/TextureManager.cpp
	src/Animation/Animation.cpp
	src/Inputs/Input.cpp
	src/Time/Clock.cpp
)

set (SDL_INCLUDE ${CMAKE_SOURCE_DIR}/vendor/SDL/include)
set (SDL_LIB_DIR ${CMAKE_SOURCE_DIR}/vendor/SDL/lib)

set (ENGINE_INCLUDE_DIR
	${CMAKE_SOURCE_DIR}/engine/src/Core
	${CMAKE_SOURCE_DIR}/engine/src/Graphics
	${CMAKE_SOURCE_DIR}/engine/src/Physics
	${CMAKE_SOURCE_DIR}/engine/src/Object
	${CMAKE_SOURCE_DIR}/engine/src/Characters
	${CMAKE_SOURCE_DIR}/engine/src/Animation
	${CMAKE_SOURCE_DIR}/engine/src/Inputs
	${CMAKE_SOURCE_DIR}/engine/src/Time)




#if (WIN32)
	#set(SDL_LIB ${SDL_LIB_DIR}/Windows/SDL2.lib
#		 SDL_LIB ${SDL_LIB_DIR}/Windows/SDL2main.lib
#	)
	#
#else()
	set(SDL_LIB ${SDL_LIB_DIR}/Linux/libSDL2.a
				${SDL_LIB_DIR}/Linux/libSDL2_image.a)
#endif()

target_link_libraries(Engine PUBLIC ${SDL_LIB})


target_include_directories(Engine PUBLIC
						   ${SDL_INCLUDE}
						   ${ENGINE_INCLUDE_DIR})
