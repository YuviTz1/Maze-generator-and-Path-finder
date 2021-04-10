#pragma once
#include<iostream>
#include<SDL.h>
class platform
{
public:
	int n = 100;
	SDL_Window* window = SDL_CreateWindow("Maze!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 640, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, n, n);
	

	platform()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cout << "SDL initialise Error" << SDL_GetError() << std::endl;
		}
		if (window == NULL)
		{
			std::cout << "Could not create window" << SDL_GetError() << std::endl;
		}
	}

	void update(int screen[])
	{
		SDL_UpdateTexture(texture, nullptr, screen, sizeof(int) * n);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, nullptr, nullptr);
		SDL_RenderPresent(renderer);
		//std::this_thread::sleep_for(0.005s);
	}

	~platform()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

};

