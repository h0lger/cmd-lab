#ifndef FONT_H
#define FONT_H

#include "SDL2/SDL_ttf.h"

class DaFont {
public:
  DaFont(const char *fontPath, int fontSize = 24, int renderSize = 24);
  ~DaFont();

  int FontSize;
  int RenderSize;

  TTF_Font *GetFont() const;
private:
  TTF_Font *_font;
};

#endif
