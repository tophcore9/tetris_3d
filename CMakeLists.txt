cmake_minimum_required(VERSION 3.20)
project(tetris3D LANGUAGES C CXX )

set(CMAKE_C_STANDARD 11)

set(RAYLIB_INCLUDE ${CMAKE_SOURCE_DIR}/raylib-5.0/include)
set(RAYLIB_LIB ${CMAKE_SOURCE_DIR}/raylib-5.0/lib/libraylib.a)

add_executable(tetris3D main.c
        figures.c
        game.c
        env.c
)

target_include_directories(tetris3D PRIVATE ${RAYLIB_INCLUDE})
target_link_libraries(tetris3D ${RAYLIB_LIB} opengl32 gdi32 winmm)