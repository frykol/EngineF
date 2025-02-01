cmake_minimum_required(VERSION 3.2)

add_executable(EngineF "main.cpp" "Logger/Logger.h")


target_link_libraries(EngineF glfw libglew_static)