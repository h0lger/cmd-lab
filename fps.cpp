#include "fps.h"
#include "dafont.h"
#include <SDL2/SDL.h>
#include "constants.h"

// --- FPS Counter Setup ---
Uint32 _fpsLastTime = SDL_GetTicks();

Fps::Fps(SDL_Renderer *renderer) {
  this->_renderer = renderer;
  _font = new DaFont(DEFAULT_MONO_FONT, 24, 24);
}

void Fps::Draw() {
  // --- FPS Counter Logic ---
  _fpsFrames++;
  Uint32 fpsCurrentTime = SDL_GetTicks();
  if (fpsCurrentTime - _fpsLastTime >= 1000) {
    _fps = _fpsFrames * 1000.0f / (fpsCurrentTime - _fpsLastTime);
    _fpsFrames = 0;
    _fpsLastTime = fpsCurrentTime;
  }
  char fpsText[32];
  snprintf(fpsText, sizeof(fpsText), "FPS: %.1f", _fps);
  SDL_Surface *fpsSurface = TTF_RenderUTF8_Blended(_font->GetFont(), fpsText, _color);
  if (fpsSurface) {
    SDL_Texture *fpsTexture =
        SDL_CreateTextureFromSurface(_renderer, fpsSurface);
    SDL_Rect fpsRect = {10, 10, fpsSurface->w, fpsSurface->h};
    SDL_FreeSurface(fpsSurface);
    if (fpsTexture) {
      SDL_RenderCopy(_renderer, fpsTexture, NULL, &fpsRect);
      SDL_DestroyTexture(fpsTexture);
    }
  }
}
