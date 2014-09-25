#include "inc/mainWindow.h"
#include <iostream>

//The window we'll be rendering to
SDL_Window* mainWindow::gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* mainWindow::gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* mainWindow::gBackground = NULL;

bool mainWindow::init() 
{
    SDL_Init (SDL_INIT_EVERYTHING);	
	bool success = true;

	// SDL_Init should return a non-zero value if there's an error, so handle it
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL failed to initialize! Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		// TODO: Center the window or/and make it fullscreen
        gWindow = SDL_CreateWindow("Slinx 0.0.1", 10, 10, 640, 480, true); 
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }		
	}
}

bool mainWindow::loadBackground() 
{
	bool success = true;

	gBackground = SDL_LoadBMP("media/bg.bmp");
	if (gBackground == NULL) {
		printf("Unable to load image! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void mainWindow::close() 
{
	SDL_FreeSurface(gBackground);
	gBackground = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

mainWindow::mainWindow()
{
	// Now we're going to call all of the previously defined functions. Notice that we're also checking their return value.
	if (!init()) {
		printf("init(): Failed to initialize!\n");
    }
    else 
    {
        if (!loadBackground()) 
        {
			printf("loadBackground(): Failed to background image!\n");
        }
        else 
        {
            // SDL_BlitSurface applies the image to the surface we previously created.
            SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL );
            // This is to ensure we actually see the window. Mind you, the value passed is in to SDL_Delay should be in milliseconds.
            SDL_Delay(2000);
        }
    }

    // Free the resources and close SDL using the previously defined close() function.
    close();  
}