#include "SDL2/SDL.h"

int main( int argc, char* args[] )
{
    // Let's hope it loads
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Quit();
    return 0;    
}
