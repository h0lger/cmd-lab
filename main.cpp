#include "background.h"
#include "dafont.h"
#include "fps.h"
#include "text.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
  // --- Initialization ---
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize! SDL error: " << SDL_GetError()
              << std::endl;
    return 1;
  }
  if (TTF_Init() < 0) {
    std::cerr << "Couldn't initialise SDL_ttf: " << TTF_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  SDL_Window *win = SDL_CreateWindow(
      "Hello SDL2!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,
      SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  if (!win) {
    std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    TTF_Quit();
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(
      win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer) {
    std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return 1;
  }
  std::unique_ptr<Fps> fpsPtr(new Fps(renderer));
  std::unique_ptr<DaFont> daFontPtr (new DaFont("/System/Library/Fonts/SFNSMono.ttf", 24, 24));
  std::unique_ptr<Text> textPtr(new Text(renderer, "Yeah hello", daFontPtr.get()));

  // --- Font and Text Setup ---
  const char *fontPath = "/System/Library/Fonts/SFNSMono.ttf";
  int renderFontSize = 24;
  int displayFontSize = 24;
  TTF_Font *font = TTF_OpenFont(fontPath, renderFontSize);
  if (!font) {
    std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return 1;
  }
  SDL_Color color = {255, 255, 255, 255};
  SDL_Surface *textSurface =
      TTF_RenderUTF8_Blended(font, "Hello, SDL2_ttf!", color);
  if (!textSurface) {
    std::cerr << "TTF_RenderUTF8_Solid Error: " << TTF_GetError() << std::endl;
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return 1;
  }
  float scale = displayFontSize / (float)renderFontSize;
  int scaledW = (int)(textSurface->w * scale);
  int scaledH = (int)(textSurface->h * scale);
  if (scaledW < 1)
    scaledW = 1;
  if (scaledH < 1)
    scaledH = 1;
  SDL_Rect dstRect = {100, 200, scaledW, scaledH};
  SDL_Texture *textTexture =
      SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_FreeSurface(textSurface);
  if (!textTexture) {
    std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError()
              << std::endl;
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    TTF_Quit();
    SDL_Quit();
    return 1;
  }

  // --- Main Loop ---
  SDL_Event e;
  bool running = true;
  while (running) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        running = false;
      if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_q)
        running = false;
    }

    DrawBackground(renderer);
    //render fps
    fpsPtr->Draw();
    textPtr->Draw();

    // Render main text
    // SDL_RenderCopy(renderer, textTexture, NULL, &dstRect);

    SDL_RenderPresent(renderer);
    SDL_Delay(10);
  }

  // --- Cleanup ---
  SDL_DestroyTexture(textTexture);
  TTF_CloseFont(font);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  TTF_Quit();
  SDL_Quit();
  return 0;
}
