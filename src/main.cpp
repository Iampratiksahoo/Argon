#include "SDL2/SDL.h"   /* All SDL App's need this */
#include <stdio.h>

#include "Core.h"

int main(int, char**) 
{
    AG_LOG("Initializing SDL.\n");

    /* Initialize defaults, Video and Audio */
    if ((SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) {
        AG_ERROR("Could not initialize SDL: %s.\n", SDL_GetError());
        exit(-1);
    }

    AG_SUCCESS("SDL initialized.\n");

    AG_WARN("Quiting SDL.\n");

    /* Shutdown all subsystems */
    SDL_Quit();

    AG_NOTICE("Quiting....\n");

    exit(0);
}