#include "filelist.h"
#include "constants.h"
#include "background.h"
#include "dafont.h"
#include "fps.h"
#include "text.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
	// --- Initialization ---
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL could not initialize! SDL error: " << SDL_GetError()
				  << std::endl;
		return 1;
	}
	if (TTF_Init() < 0)
	{
		std::cerr << "Couldn't initialise SDL_ttf: " << TTF_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow(
		"Commander", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 900,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	if (!win)
	{
		std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(
		win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(win);
		TTF_Quit();
		SDL_Quit();
		return 1;
	}
	std::unique_ptr<Fps> fpsPtr(new Fps(renderer));
	std::unique_ptr<Background> backgroundPtr(new Background(renderer));
	std::unique_ptr<Filelist> filelistPtr(new Filelist(renderer));

	// --- Main Loop ---
	SDL_Event e;
	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				running = false;
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
				running = false;
		}

		backgroundPtr->Draw();
		// render fps
		fpsPtr->Draw();
		filelistPtr->Draw({"file1.txt", "file2.txt", "file3.txt"});

		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}

	// --- Cleanup ---
	fpsPtr.reset();
	backgroundPtr.reset();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	TTF_Quit();
	SDL_Quit();
	return 0;
}
