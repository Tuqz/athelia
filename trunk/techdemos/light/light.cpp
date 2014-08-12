#include <iostream>
#include <cmath>
#include <algorithm>
#include "SDL/SDL.h"
#include <camera.h>
#include <plane.h>
#include <vector.h>
#include <colour.h>
#include <trace.h>
#include "../utils.hpp"

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	Renderer::Camera cam = Renderer::Camera();
	std::vector<Renderer::Renderable*> ents;
	Renderer::Plane light = Renderer::Plane(Vector(2, 0, 0), Vector(-1, 0, 0), Vector(0, 1, 0), 2, 2, Renderer::RED, true);
	ents.push_back(&light);
	SDL_Surface* screen = SDL_SetVideoMode(cam.pixels, cam.pixels, 32, SDL_SWSURFACE);
	SDL_PixelFormat* format = screen->format;
	bool quit = false;
	while(!quit) {
		SDL_Event event; 
		while(SDL_PollEvent(&event)) {
			auto update = event_handler(event, cam);
			quit = update.first;
			cam = update.second;
		}
		SDL_LockSurface(screen);
		for(int i = 0; i < cam.pixels*cam.pixels; ++i) {
			Renderer::Colour col = Renderer::trace(cam.rays[i], ents);
			set_pixel(screen, i/cam.pixels, i%cam.pixels, SDL_MapRGB(format, col.red*255, col.green*255, col.blue*255));
		}
		SDL_UnlockSurface(screen);
		SDL_Flip(screen);
	}
	SDL_Quit();
	return 0;
}
