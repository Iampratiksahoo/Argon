#include "Game.h"

#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>

#include "Core.h"
#include "RenderWindow.h"

Game::Game() : 
    m_gameRunning(false),
    m_renderWindow(nullptr),
    m_event(nullptr)
{
    initSDL();

    // Set the game Running flag to true
    m_gameRunning = true;

    // init the render window
    m_renderWindow = new RenderWindow("Argon", 800, 600);

    // init the event
    m_event = new SDL_Event();

    update();
}

void Game::update()
{
    while (m_gameRunning)
    {
        pollEvents();


        // TEST
        m_renderWindow->Clear();
        m_renderWindow->Render(m_renderWindow->GetOrLoadTexture("res/images/ab.png"));
        m_renderWindow->Display();
    }
}

void Game::cleanup()
{
    AG_WARN("Stopping the game.");

    m_gameRunning = false;

    AG_WARN("Quiting SDL.");

    /* Shutdown all subsystems */
    SDL_Quit();
}

void Game::initSDL()
{
    AG_LOG("Initializing SDL...");

    uint32_t flags =
        SDL_INIT_VIDEO |
        SDL_INIT_AUDIO;

    /* Initialize defaults, Video and Audio */
    if ((SDL_Init(flags) == -1))
    {
        AG_ERROR("Could not initialize SDL: %s.", SDL_GetError());
        exit(-1);
    }

    AG_SUCCESS("Successfully initialized SDL.");

    AG_LOG("Starting game...");
}

void Game::pollEvents()
{
    while (SDL_PollEvent(m_event))
    {
        switch (m_event->type)
        {

        case SDL_QUIT:
            cleanup();
            return;

        default:
            break;
        }
    }
}
