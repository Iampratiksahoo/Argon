#pragma once

class Game
{
public: 
	Game();
	~Game() = default;

protected:
	/// <summary>
	/// Initializes SDL2 and all the Game Modules
	/// </summary>
	void initSDL();

	/// <summary>
	/// Updates all the game modules every frame
	/// </summary>
	void update();

	/// <summary>
	/// Polls all the SDL Events and also runs the update.
	/// </summary>
	void pollEvents();

	/// <summary>
	/// Performs cleanup on all the game modules once the game has finished 
	/// </summary>
	void cleanup();



private: 
	bool m_gameRunning; 

	class RenderWindow* m_renderWindow; 

	union SDL_Event* m_event;
};


