#include "text.h"
#include "SDL2/SDL_render.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

Text::Text(SDL_Renderer *renderer, const char *text, const DaFont *font) {
  this->_text = text;
  this->_font = font;
  this->_renderer = renderer;

  this->_textSurface = TTF_RenderUTF8_Blended(this->_font->GetFont(), this->_text, this->_color);
  if (!this->_textSurface) {
    std::cerr << "TTF_RenderUTF8_Solid Error: " << TTF_GetError() << std::endl;
    throw std::runtime_error("Failed to render text surface");
    // TTF_CloseFont(font);
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(win);
    // TTF_Quit();
    // SDL_Quit();
    // return 1;
  }
  float scale = this->_font->FontSize / (float)this->_font->RenderSize;
  int scaledW = (int)(this->_textSurface->w * scale);
  int scaledH = (int)(this->_textSurface->h * scale);
  if (scaledW < 1)
    scaledW = 1;
  if (scaledH < 1)
    scaledH = 1;
  this->_dstRect = {100, 200, scaledW, scaledH};
  this->_textTexture = SDL_CreateTextureFromSurface(this->_renderer, this->_textSurface);
  SDL_FreeSurface(this->_textSurface);
  if (!this->_textTexture) {
    std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError()
              << std::endl;
  }
}
Text::~Text() {
    SDL_DestroyTexture(this->_textTexture);
}
void Text::Draw() {
  // Render main text
  SDL_RenderCopy(this->_renderer, this->_textTexture, NULL, &this->_dstRect);
}
