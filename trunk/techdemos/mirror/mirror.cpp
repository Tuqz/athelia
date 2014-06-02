#include <iostream>
#include <cmath>
#include <algorithm>
#include "SDL/SDL.h"
#include <camera.h>
#include <plane.h>
#include <vector.h>
#include <trace.h>

void set_pixel(SDL_Surface* surface, int x, int y, Uint32 colour) {
	Uint32* pixels = (Uint32* )surface->pixels;
	pixels[(y*surface->w)+x] = colour;
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	Camera cam = Camera();
	std::vector<Plane> ents;
	ents.push_back(Plane(Vector(2, 0, 0), Vector(-1, 0, 0), Vector(0, 1, 0), 2, 2, YELLOW, true));
	ents.push_back(Plane(Vector(1.5, 0, 1.25), Vector(0, 0, -1), Vector(0, 1, 0), 2, 2, RED, false));
	SDL_Surface* screen = SDL_SetVideoMode(cam.pixels, cam.pixels, 32, SDL_SWSURFACE);
	SDL_PixelFormat* format = screen->format;
	double conversion = 3.14159/180;
	bool quit = false;
	while(!quit) {
		SDL_Event event; 
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				quit = true;
			} else {
				if(event.type == SDL_KEYDOWN) {
					switch(event.key.keysym.sym) {
						case 'w':
							cam.tilt(-10*conversion);
							break;
						case 's':
							cam.tilt(10*conversion);
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
		}
		SDL_LockSurface(screen);
		for(int i = 0; i < cam.pixels*cam.pixels; ++i) {
			Colour col = trace(cam.rays[i], ents);
			set_pixel(screen, i/cam.pixels, i%cam.pixels, SDL_MapRGB(format, col.red*255, col.green*255, col.blue*255));
		}
		SDL_UnlockSurface(screen);
		SDL_Flip(screen);
		cam.reset_rays();
	}
	SDL_Quit();
	return 0;
}
