file(GLOB run_file_src "*.cpp")
include_directories(${default_incs})
add_executable(run_file ${run_file_src})
target_link_libraries(run_file ${DEFAULT_LIBS} ${LUA_LIBRARIES})
