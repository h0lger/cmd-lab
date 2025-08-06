#include "background.h"
#include "SDL2/SDL_render.h"
#include <SDL2/SDL.h>

Background::Background(SDL_Renderer *renderer) { this->_renderer = renderer; }
Background::~Background() {}
void Background::Draw() {
  // Draw vertical gradient background using actual renderer size
  int winW, winH;
  SDL_GetRendererOutputSize(this->_renderer, &winW, &winH);
  for (int y = 0; y < winH; ++y) {
    Uint8 r = (Uint8)(30 + 25 * y / winH);
    Uint8 g = (Uint8)(30 + 100 * y / winH);
    Uint8 b = (Uint8)(30 + 180 * y / winH);
    SDL_SetRenderDrawColor(this->_renderer, r, g, b, 255);
    SDL_RenderDrawLine(this->_renderer, 0, y, winW, y);
  }
}
