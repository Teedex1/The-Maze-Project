#include <SDL.h>
#include <stdio.h>

int main(__attribute__((unused)) int argc, __attribute__((unused)) char* args[] )
{
	/*setenv("XDG_RUNTIME_DIR", "/tmp", 1); //Added*/

	SDL_Window* window = NULL;

	SDL_Surface* screenSurface = NULL;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			screenSurface = SDL_GetWindowSurface( window );

			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

			SDL_UpdateWindowSurface( window );

			SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}

	SDL_DestroyWindow( window );

	SDL_Quit();

	return 0;
=======
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );
    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if( renderer == NULL )
    {
        printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
        SDL_DestroyWindow( window );
        return 1;
    }

    // Main loop
    bool quit = false;
    SDL_Event e;
    while( !quit )
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );

        // Update screen
        SDL_RenderPresent( renderer );
    }

    // Cleanup
    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
>>>>>>> bdea74e5179bf7bbec7da8c99334353e51f96ada
}
