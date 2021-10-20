#include "../include/Game.h"

Game::Game() :
    m_gameIsRunning{ false }
{  
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
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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
    legoButton = loadFromFile("../resources/images/legobr.bmp", legoButton, legoButtonData);
    legoButtonData.x = 0;
    legoButtonData.y = 0;

    clayButton = loadFromFile("../resources/images/claybr.bmp", clayButton, clayButtonData);
    clayButtonData.x = 256;
    clayButtonData.y = 0;

    concreteButton = loadFromFile("../resources/images/concretebr.bmp", concreteButton, concreteButtonData);
    concreteButtonData.x = 0;
    concreteButtonData.y = 256;

    timberButton = loadFromFile("../resources/images/timberbr.bmp", timberButton, timberButtonData);
    timberButtonData.x = 256;
    timberButtonData.y = 256;
    
    undoButton = loadFromFile("../resources/images/undo.bmp", undoButton, undoData);
    undoData.x = 256 + undoData.width * 2.0;
    undoData.y = 0;

    redoButton = loadFromFile("../resources/images/redo.bmp", redoButton, redoData);
    redoData.x = 256 + redoData.width * 2.0;
    redoData.y = redoData.height;

    executeButton = loadFromFile("../resources/images/execute.bmp", executeButton, executeButtonData);
    executeButtonData.x = 256 + executeButtonData.width * 2.0;
    executeButtonData.y = executeButtonData.height * 2;
}

SDL_Texture* Game::loadFromFile(std::string path, SDL_Texture* tex, TextureData& data)
{
    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());

    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError());
    }
    else
    {
        std::cout << "loadedSurface set :)" << std::endl;
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        //Create texture from surface pixels
        tex = SDL_CreateTextureFromSurface(renderer, loadedSurface);


        if (tex == NULL)
        {
            std::cout << "Unable to create texture from %s! SDL Error: %s\n" << path.c_str() << SDL_GetError() << std::endl;
        }
        else
        {
            std::cout << "tex loaded :)" << std::endl;
            //Get image dimensions
            data.width = loadedSurface->w;
            data.height = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return tex;
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

        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            processMouse(e.button);
        }
    }
}

void Game::processMouse(SDL_MouseButtonEvent& b)
{
    if(b.button == SDL_BUTTON_LEFT){
    //handle a left-click
        if(b.x >= legoButtonData.x && b.x <= legoButtonData.x + legoButtonData.width)
        {
            if(b.y >= legoButtonData.y && b.y <= legoButtonData.y + legoButtonData.height)
            {
                macro.add(new LegoCommand());
            }
        }

        if(b.x >= clayButtonData.x && b.x <= clayButtonData.x + clayButtonData.width)
        {
            if(b.y >= clayButtonData.y && b.y <= clayButtonData.y + clayButtonData.height)
            {
                macro.add(new ClayCommand());
            }
        }

        if(b.x >= concreteButtonData.x && b.x <= concreteButtonData.x + concreteButtonData.width)
        {
            if(b.y >= concreteButtonData.y && b.y <= concreteButtonData.y + concreteButtonData.height)
            {
                macro.add(new ConcreteCommand());
            }
        }

        if(b.x >= timberButtonData.x && b.x <= timberButtonData.x + timberButtonData.width)
        {
            if(b.y >= timberButtonData.y && b.y <= timberButtonData.y + timberButtonData.height)
            {
                macro.add(new TimberCommand());
            }
        }

        if(b.x >= undoData.x && b.x <= undoData.x + undoData.width)
        {
            if(b.y >= undoData.y && b.y <= undoData.y + undoData.height)
            {
                macro.undo();
            }
        }

        if(b.x >= redoData.x && b.x <= redoData.x + redoData.width)
        {
            if(b.y >= redoData.y && b.y <= redoData.y + redoData.height)
            {
                macro.redo();
            }
        }

        if(b.x >= executeButtonData.x && b.x <= executeButtonData.x + executeButtonData.width)
        {
            if(b.y >= executeButtonData.y && b.y <= executeButtonData.y + executeButtonData.height)
            {
                macro.execute();
            }
        }
  }
}

void Game::update()
{
   // std::cout << "Updating" << std::endl;
}

void Game::renderTexture(SDL_Texture* t_tex, TextureData t_data)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad;
    renderQuad.x = t_data.x;
    renderQuad.y = t_data.y;
    renderQuad.w = t_data.width;
    renderQuad.h = t_data.height;
    
    //Render to screen
    SDL_RenderCopy(renderer, t_tex, NULL, &renderQuad);
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
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderClear(renderer);

        renderTexture(legoButton, legoButtonData);

        renderTexture(clayButton, clayButtonData);

        renderTexture(concreteButton, concreteButtonData);

        renderTexture(timberButton, timberButtonData);

        renderTexture(undoButton, undoData);

        renderTexture(redoButton, redoData);

        renderTexture(executeButton, executeButtonData);

        SDL_RenderPresent(renderer);
    }


}

void Game::cleanUp()
{
    std::cout << "Cleaning up" << std::endl;    

    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();

    //Quit SDL subsystems
    SDL_Quit();
}