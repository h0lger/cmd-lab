#ifndef FILELIST_H
#define FILELIST_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

class Filelist{
    public:
    Filelist(SDL_Renderer *renderer);
    ~Filelist();

    void Draw(const std::vector<std::string> &files);
    private:
    SDL_Renderer *_renderer;

};

#endif