#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "TextureData.h"
#include "MacroCommand.h"
#include "LegoCommand.h"
#include "ClayCommand.h"
#include "ConcreteCommand.h"
#include "TimberCommand.h"

class Game
{
public:

    Game();
    ~Game();
    void run();

private:

    //Loads media
    void loadMedia();

    SDL_Texture* loadFromFile(std::string path, SDL_Texture* tex, TextureData& data);
    void renderTexture(SDL_Texture* t_tex, TextureData t_data);  

    //Frees media and shuts down SDL
    void close();

    void processEvents();
    void processMouse(SDL_MouseButtonEvent& b);
    void update();
    void render();

    void cleanUp();

    bool m_gameIsRunning;

    //Event handler
    SDL_Event e;

    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 512;

    //The window we'll be rendering to
    SDL_Window* window = NULL;

     //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    // Renders stuff idk?
    SDL_Renderer* renderer = NULL;

    SDL_Texture* legoButton = NULL;
    TextureData legoButtonData;

    SDL_Texture* clayButton = NULL;
    TextureData clayButtonData;

    SDL_Texture* concreteButton = NULL;
    TextureData concreteButtonData;

    SDL_Texture* timberButton = NULL;
    TextureData timberButtonData;

    SDL_Texture* undoButton = NULL;
    TextureData undoData;

    SDL_Texture* redoButton = NULL;
    TextureData redoData;

    SDL_Texture* executeButton = NULL;
    TextureData executeButtonData;

    MacroCommand macro;

};