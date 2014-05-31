cmake_minimum_required(VERSION 2.8)
project(Athelia)

add_definitions("-std=c++11")

find_package(SDL REQUIRED)
if(NOT SDL_FOUND)
	message(FATAL_ERROR "SDL is required to build Athelia")
else()
	INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS})
endif()

set(render_include_dir "${PROJECT_SOURCE_DIR}/src/renderer")
set(default_incs ${render_include_dir})
set(DEFAULT_LIBS "athelia-renderer")
add_subdirectory(src/renderer)

if(build_techdemos)
	message(WARNING "Will build techdemos. HERE BE LINKER ERRORS")
	add_subdirectory(techdemos/light)
endif()
