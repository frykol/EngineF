cmake_minimum_required(VERSION 3.5)


FILE(GLOB_RECURSE SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
FILE(GLOB_RECURSE HEADER "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_executable(EngineF ${SOURCE} ${HEADER})

target_link_libraries(EngineF glfw libglew_static)