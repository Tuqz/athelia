cmake_minimum_required(VERSION 2.8)
project(Athelia)

add_definitions("-std=c++11 -Wall -pedantic -O3 -ffast-math")

find_package(SDL REQUIRED)
if(NOT SDL_FOUND)
	message(FATAL_ERROR "SDL is required to build Athelia")
endif()
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})

set(render_include_dir "${PROJECT_SOURCE_DIR}/src/renderer")
set(default_incs ${render_include_dir})
set(DEFAULT_LIBS "athelia-renderer")
add_subdirectory(src/renderer)

if(build_techdemos)
	add_subdirectory(techdemos/light)
	add_subdirectory(techdemos/mirror)
	add_subdirectory(techdemos/cube)
	add_subdirectory(techdemos/triangle)
endif()
