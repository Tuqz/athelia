cmake_minimum_required(VERSION 2.8)
project(Athelia)

add_definitions("-std=c++11 -Wall -pedantic -O3 -ffast-math")

find_package(SDL REQUIRED)
if(NOT SDL_FOUND)
	message(FATAL_ERROR "SDL is required to build Athelia")
endif()
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})

find_package(Lua REQUIRED)
if(NOT LUA_FOUND)
	message(FATAL_ERROR "Lua is required to build Athelia")
endif()

INCLUDE_DIRECTORIES(${LUA_INCLUDE_DIR})

set(render_include_dir "${PROJECT_SOURCE_DIR}/src/renderer")
set(lua_include_dir "${PROJECT_SOURCE_DIR}/src/lua")
set(default_incs ${render_include_dir})
set(default_incs ${default_incs} ${lua_include_dir})
set(DEFAULT_LIBS "athelia-renderer")
set(DEFAULT_LIBS ${DEFAULT_LIBS} "athelia-lua")
add_subdirectory(src/renderer)
add_subdirectory(src/lua)

if(build_techdemos)
	add_subdirectory(techdemos/rendering/light)
	add_subdirectory(techdemos/rendering/mirror)
	add_subdirectory(techdemos/rendering/cube)
	add_subdirectory(techdemos/rendering/triangle)
	add_subdirectory(techdemos/lua/run_file)
endif()
