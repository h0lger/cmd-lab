#include <SDL2/SDL.h>

void DrawBackground(SDL_Renderer *renderer)
{
	// Draw vertical gradient background using actual renderer size
	int winW, winH;
	SDL_GetRendererOutputSize(renderer, &winW, &winH);
	for (int y = 0; y < winH; ++y)
	{
		Uint8 r = (Uint8)(30 + 225 * y / winH);
		Uint8 g = (Uint8)(30 + 100 * y / winH);
		Uint8 b = (Uint8)(30 + 180 * y / winH);
		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		SDL_RenderDrawLine(renderer, 0, y, winW, y);
	}
}