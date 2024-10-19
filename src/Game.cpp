#include "Game.h"

#include "SDL2/SDL.h"
#include <stdio.h>
#include <iostream>

#include "Core.h"
#include "RenderWindow.h"
#include "Vector2.h"

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

    auto vec1 = Vector2<int>(2, 3);
    auto vec2 = Vector2<int>(4, 5);
    AG_WARN("Vector1: %s", vec1.ToString());
    AG_WARN("Vector2: %s", vec2.ToString());
    AG_WARN("Vector Add: %s", (vec1 + vec2).ToString());
    AG_WARN("Vector Minus: %s", (vec1 - vec2).ToString());
    AG_WARN("Vector Float Add: %s", (vec2 + 5.f).ToString());
    AG_WARN("Vector Float Minus: %s", (vec2 - 5.0).ToString());
    AG_WARN("Vector Float Multiply: %s", (vec2 * 5).ToString());

    update();
}

void Game::update()
{
    while (m_gameRunning)
    {
        pollEvents();
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
