#pragma once

class RenderWindow
{
public:
	RenderWindow(const char* name, int width, int height);
	~RenderWindow();

private:
	struct SDL_Window* m_window;
	struct SDL_Renderer* m_renderer;
};