#ifndef TEXT_H
#define TEXT_H
#include "SDL2/SDL_render.h"
#include "dafont.h"
#include <SDL2/SDL.h>

class Text {
public:
  Text(SDL_Renderer *renderer, const char *text, const DaFont *font);
  ~Text();

  void Draw();

private:
  const char *_text;
  const DaFont *_font;
  SDL_Renderer *_renderer;
  SDL_Surface *_textSurface;
  SDL_Rect _dstRect;
  SDL_Texture *_textTexture;
  SDL_Color _color = {255, 255, 255, 255};
};

#endif
