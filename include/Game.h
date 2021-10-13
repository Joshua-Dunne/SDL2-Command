#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Game
{
public:

    Game();
    ~Game();
    void run();

private:

    //Loads media
    void loadMedia();
    //Frees media and shuts down SDL
    void close();

    void processEvents();
    void update();
    void render();

    void cleanUp();

    bool m_gameIsRunning;

    //Event handler
    SDL_Event e;

    //Screen dimension constants
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //The image we will load and show on the screen
    SDL_Surface* gHelloWorld = NULL;

};