#include "dafont.h"
#include "iostream"
#include <SDL2/SDL_ttf.h>



DaFont::DaFont(const char *fontPath, int fontSize, int renderSize) {
  // Initialize the font using the provided path
  this->FontSize = fontSize;
  this->RenderSize = renderSize;
  this->_font = TTF_OpenFont(fontPath, this->FontSize);
  if (!_font) {
    std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    throw std::runtime_error("Failed to load font");
    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(win);
    // TTF_Quit();
    // SDL_Quit();
  }
}
TTF_Font *DaFont::GetFont() const { return _font; }

DaFont::~DaFont() {
  // Clean up resources
}
