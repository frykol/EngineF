cmake_minimum_required(VERSION 3.5)

project("EngineF")

add_subdirectory("glfw")
add_subdirectory("glew")
add_subdirectory("glm")
add_subdirectory("EngineF")

target_include_directories("EngineF" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include)
target_include_directories("EngineF" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glew/include)
target_include_directories("EngineF" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glm)