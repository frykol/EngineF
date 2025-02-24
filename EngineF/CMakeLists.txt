cmake_minimum_required(VERSION 3.5)

add_custom_target(c ALL)
add_custom_command(TARGET c POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/textures
	${CMAKE_CURRENT_BINARY_DIR}/textures)

add_custom_command(TARGET c POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/shaders
	${CMAKE_CURRENT_BINARY_DIR}/shaders)

	add_custom_command(TARGET c POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/fonts
	${CMAKE_CURRENT_BINARY_DIR}/fonts)

FILE(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
FILE(GLOB_RECURSE HEADER "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_executable(EngineF ${SOURCE} ${HEADER})

target_link_libraries(EngineF glfw libglew_static freetype)