add_executable(SP26_Shinji_Kusakabe Game.cpp)

target_link_libraries(SP26_Shinji_Kusakabe Tonkatsu)

target_sources(SP26_Shinji_Kusakabe PUBLIC Ball.h Ball.cpp Globals.h Globals.cpp Paddle.h Paddle.cpp)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR}/SP26_Shinji_Kusakabe)