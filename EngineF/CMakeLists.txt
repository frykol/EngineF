cmake_minimum_required(VERSION 3.2)

add_executable(EngineF "main.cpp")


target_link_libraries(EngineF glfw libglew_static)