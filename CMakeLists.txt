cmake_minimum_required(VERSION 3.24)

project(MyGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(glfw)
add_subdirectory(Hat)
add_subdirectory(SP26_Shinji_Kusakabe)

set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SP26_Shinji_Kusakabe)