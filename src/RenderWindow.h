#pragma once

// TODO: Move this from here, we don't need this here!!! 
#include <list>
#include <map>

struct SDL_Texture;
struct SDL_Window;
struct SDL_Renderer;
class RenderWindow
{
public:
	RenderWindow(const char* name, int width, int height);
	~RenderWindow();

	SDL_Texture* GetOrLoadTexture(const char* texturePath, bool forceReload = false);

	void Clear();
	void Render(SDL_Texture* texture);
	void Display();

protected:
	SDL_Texture* loadTexture(const char* texturePath);

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	std::map<const char*, SDL_Texture*> m_textureCache;
};	