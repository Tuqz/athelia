#include <iostream>
#include <cmath>
#include <algorithm>
#include "SDL/SDL.h"
#include <camera.h>
#include <plane.h>
#include <vector.h>

void set_pixel(SDL_Surface* surface, int x, int y, Uint32 colour) {
	Uint32* pixels = (Uint32* )surface->pixels;
	pixels[(y*surface->w)+x] = colour;
}

int main() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTTHREAD);
	Camera cam = Camera();
	std::vector<Plane> ents;
	ents.push_back(Plane(Vector(2, 0, 0), Vector(-1, 0, 0), Vector(0, 1, 0), 2, 2, 1, true));
	SDL_Surface* screen = SDL_SetVideoMode(cam.pixels, cam.pixels, 32, SDL_SWSURFACE);
	SDL_PixelFormat* format = screen->format;
	double conversion = 3.14159/180;
	double rate = 0.5;
	bool quit = false;
	while(!quit) {
		SDL_Event event; 
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
			}
		}
		SDL_LockSurface(screen);
		for(int i = 0; i < cam.pixels*cam.pixels; ++i) {
			cam.rays[i].trace(ents);
			double intens = cam.rays[i].intensity;
			set_pixel(screen, i/cam.pixels, i%cam.pixels, SDL_MapRGB(format, intens*255, intens*255, intens*255));
		}
		SDL_UnlockSurface(screen);
		SDL_Flip(screen);
		cam.reset_rays();
	}
	SDL_Quit();
	return 0;
}
