#pragma once
#include "SDL/SDL.h"
#include <utility>
#include <camera.h>

#define PI 3.14159
#define conversion PI/180

void set_pixel(SDL_Surface* surface, int x, int y, Uint32 colour) {
	Uint32* pixels = (Uint32* )surface->pixels;
	int map_y = surface->h - y - 1;
	pixels[(map_y*surface->w)+x] = colour;
}

std::pair<bool, Camera> event_handler(SDL_Event event, Camera cam) {
	if(event.type == SDL_QUIT) {
		return std::make_pair(true, cam);
	} else {
		if(event.type == SDL_KEYDOWN) {
			switch(event.key.keysym.sym) {
				case 'w':
					cam.tilt(10*conversion);
					break;
				case 's':
					cam.tilt(-10*conversion);
					break;
				case 'a':
					cam.pan(10*conversion);
					break;
				case 'd':
					cam.pan(-10*conversion);
					break;
				case 'q':
					cam.roll(10*conversion);
					break;
				case 'e':
					cam.roll(-10*conversion);
					break;
				case SDLK_UP:
					cam.translate(cam.normal*0.25);
					break;
				case SDLK_DOWN:
					cam.translate(cam.normal*-0.25);
					break;
				case SDLK_LEFT:
					cam.translate(Vector::cross(cam.normal, cam.up)*-0.25);
					break;
				case SDLK_RIGHT:
					cam.translate(Vector::cross(cam.normal, cam.up)*0.25);
					break;
				default:
					break;
			}
		}
	}
	return std::make_pair(false, cam);
}
