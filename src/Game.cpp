#include "../include/Game.h"

Game::Game() :
    m_gameIsRunning{ false }
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    }

    macro.add(new TimberCommand());
    macro.add(new LegoCommand());

    macro.execute();

    std::cin.get();
}

Game::~Game()
{
    cleanUp();
}

void Game::run()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
        }
    }

    loadMedia();

    m_gameIsRunning = true;
    while (m_gameIsRunning)
    {
        processEvents();
        update();
        render();
    }
}

void Game::loadMedia()
{
    //Load splash image
    gHelloWorld = SDL_LoadBMP( "../resources/images/legobr.bmp" );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "resources/images/legobr.bmp", SDL_GetError() );
    }
}

void Game::processEvents()
{
    //std::cout << "Processing Events" << std::endl;
    //While application is running
    while(SDL_PollEvent( &e ) != 0)
    {
        //User requests quit
        if(e.type == SDL_QUIT)
        {
            m_gameIsRunning = false;
        }
    }
}

void Game::update()
{
   // std::cout << "Updating" << std::endl;
}

void Game::render()
{
    //std::cout << "Rendering" << std::endl;

    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Get window surface
        screenSurface = SDL_GetWindowSurface( window );

        //Fill the surface white
        SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

        //Apply the image
        SDL_BlitSurface( gHelloWorld, NULL, screenSurface, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( window );
    }


}

void Game::cleanUp()
{
    std::cout << "Cleaning up" << std::endl;

    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();

    //Quit SDL subsystems
    SDL_Quit();
}