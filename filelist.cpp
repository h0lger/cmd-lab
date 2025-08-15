#include "filelist.h"
#include "text.h"
#include "constants.h"
const uint8_t PANE_PADDING = 50;
const uint8_t HALF_PANE_PADDING = PANE_PADDING / 2;

Filelist::Filelist(SDL_Renderer *renderer) : _renderer(renderer)
{
	_renderer = renderer;
}
Filelist::~Filelist()
{
}
void Filelist::Draw(const std::vector<std::string> &files)
{
	DrawPanes();
	DrawFileList(files);
	DrawSelector();
}

void Filelist::DrawFileList(const std::vector<std::string> &files)
{
	const std::unique_ptr<DaFont> daFontPtr(
			new DaFont(DEFAULT_MONO_FONT, 24, 24));
	// text
	uint n = 10;
	
	std::for_each(files.begin(), files.end(), [&](const std::string &file)
	{
		const std::unique_ptr<Text> textPtr(
			new Text(leftPane.x + 10, leftPane.y + n, _renderer, file.c_str(), daFontPtr.get()));
		textPtr->Draw();
		n += 30; // increment y position for next file
	});

}
void Filelist::DrawSelector()
{
	// Draw a selector rectangle around the currently selected file
	SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(_renderer, 0, 200, 255, 200); // Red color for selector
	SDL_Rect selectorRect = {leftPane.x + 5, leftPane.y + 5, leftPane.w - 10, 30};
	SDL_RenderFillRect(_renderer, &selectorRect);
}
void Filelist::DrawPanes()
{
	// rectangles
	int winW, winH;
	SDL_GetRendererOutputSize(_renderer, &winW, &winH);
	leftPane = {0, 50, (winW / 2) - HALF_PANE_PADDING, winH - 100};
	rightPane = {(winW / 2), 50, (winW / 2) - HALF_PANE_PADDING, winH - 100};

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(_renderer, &leftPane);
	SDL_RenderDrawRect(_renderer, &rightPane);
}