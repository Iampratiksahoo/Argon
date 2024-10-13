#include "RenderWindow.h"

#include "Core.h"
#include "SDL2/SDL.h"

RenderWindow::RenderWindow(const char* title, int width, int height) :
	m_window(nullptr)
{
	AG_LOG("Initializing RenderWindow...");

	m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (m_window == nullptr)
	{
		AG_ERROR("Failed to initialize SDL Window: %s.", SDL_GetError());
		exit(-1);
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr)
	{
		AG_ERROR("Failed to initialize SDL Renderer: %s.", SDL_GetError());
		exit(-1);
	}

	AG_SUCCESS("Successfully initialized RenderWindow");
}

RenderWindow::~RenderWindow()
{
	AG_WARN("Destroying RenderWindow.");

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}
