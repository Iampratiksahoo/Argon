#include "RenderWindow.h"

#include "Core.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

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

SDL_Texture* RenderWindow::GetOrLoadTexture(const char* texturePath, bool forceReload)
{
	if (m_textureCache.find(texturePath) != m_textureCache.end())
	{
		if (forceReload)
		{
			m_textureCache.erase(texturePath);
			goto LoadTexture;
		}
		return m_textureCache[texturePath];
	}

LoadTexture:
	if (SDL_Texture* texture = loadTexture(texturePath))
	{
		return m_textureCache[texturePath] = texture;
	}
	return nullptr;
}

void RenderWindow::Clear()
{
	SDL_RenderClear(m_renderer);
}

void RenderWindow::Render(SDL_Texture* texture)
{
	SDL_RenderCopy(m_renderer, texture, nullptr, nullptr);
}

void RenderWindow::Display()
{
	SDL_RenderPresent(m_renderer);
}

SDL_Texture* RenderWindow::loadTexture(const char* texturePath)
{
	AG_LOG("Loading Texture from path: %s", texturePath);
	SDL_Texture* texture = nullptr;

	texture = IMG_LoadTexture(m_renderer, texturePath);

	if (texture == nullptr)
	{
		AG_ERROR("Failed to Load Texture from path: %s", texturePath);
	}

	return texture;
}