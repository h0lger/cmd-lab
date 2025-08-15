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
		SDL_Rect leftPane, rightPane;

		// Draws the left and right panes
		void DrawPanes();
		// Draws the file list in the left pane
		void DrawFileList(const std::vector<std::string> &files);
		void DrawSelector();

};

#endif