file(GLOB light_src "*.cpp")
include_directories(${default_incs} ${SDL_LIBRARIES})
add_executable(light ${light_src})
target_link_libraries(light ${DEFAULT_LIBS} ${SDL_LIBRARIES})
