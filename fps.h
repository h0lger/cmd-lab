#ifndef FPS_H
#define FPS_H

#include "dafont.h"
#include <SDL2/SDL.h>
class Fps {
    private:
    SDL_Renderer *_renderer;
    int _fpsFrames = 0;
    float _fps = 0.0f;
    SDL_Color _color = {255, 255, 255, 255};
    DaFont *_font;

    public:
    Fps(SDL_Renderer *renderer);
    void Init();
    void Draw();
};

#endif
