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
	const std::unique_ptr<DaFont> daFontPtr(
			new DaFont(DEFAULT_MONO_FONT, 24, 24));

	// rectangles
	int winW, winH;
	SDL_GetRendererOutputSize(_renderer, &winW, &winH);
	SDL_Rect rectLeft = {0, 50, (winW / 2) - HALF_PANE_PADDING, winH - 100};
	SDL_Rect rectRight = {(winW / 2), 50, (winW / 2) - HALF_PANE_PADDING, winH - 100};

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(_renderer, &rectLeft);
	SDL_RenderDrawRect(_renderer, &rectRight);

	// text
	uint n = 10;
	
	std::for_each(files.begin(), files.end(), [&](const std::string &file)
	{
		const std::unique_ptr<Text> textPtr(
			new Text(rectLeft.x + 10, rectLeft.y + n, _renderer, file.c_str(), daFontPtr.get()));
			textPtr->Draw();
			n += 30; // increment y position for next file
	});
}