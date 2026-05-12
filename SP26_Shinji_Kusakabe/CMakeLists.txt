add_executable(SP26_Shinji_Kusakabe Game.cpp)

target_link_libraries(SP26_Shinji_Kusakabe Tonkatsu)

file(COPY Assets Destination ${CMAKE_BINARY_DIR})