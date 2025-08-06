#include <SDL2/SDL.h>
#include <vector>

class Filelist{
    public:
    Filelist(SDL_Renderer *renderer);
    ~Filelist();

    void Draw(const std::vector<std::string> &files);
    private:
    SDL_Renderer *_renderer;

};
