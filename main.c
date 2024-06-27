#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define UNUSED(x) (void)(x)

// Screen dimension:
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** args)
{
	UNUSED(argc);
	UNUSED(args);
	
    // Render the window:
    SDL_Window* window = NULL;

    // The sdl surface:
    SDL_Surface* screenSurface = NULL;

    // Initialize SDL engine:
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        // Create a window:
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            // Get the window surface:
            screenSurface = SDL_GetWindowSurface( window );

            // Fill the window surface white:
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            // Update the window surface:
            SDL_UpdateWindowSurface( window );

            // Keep the window running trick:
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }

    // Destroy the window:
    SDL_DestroyWindow( window );

    // Quit SDL:
    SDL_Quit();

    return 0;
}