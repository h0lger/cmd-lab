#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL2/SDL.h>

class Background{
    public:
    Background(SDL_Renderer *renderer);
    ~Background();

    void Draw();
    private:
    SDL_Renderer *_renderer;

};
#endif
