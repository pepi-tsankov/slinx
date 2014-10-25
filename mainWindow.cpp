#include "inc/mainWindow.h"
#include "SDL_ttf.h"
#include <iostream>
#include <stdio.h>

SDL_Window* mainWindow::gWindow = NULL;
SDL_Surface* mainWindow::gScreenSurface = NULL;
SDL_Surface* mainWindow::gBackground = NULL;
SDL_Surface* mainWindow::sTitle = NULL;

/**
    void mainWindow::init()

    Initializes SDL and thus the main window that contains the main game menu.

    TODO: center the window or pass FULLSCREEN parameter to SDL_CreateWindow
*/
//using namespace std;
void mainWindow::init() {
    SDL_Init (SDL_INIT_EVERYTHING);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL failed to initialize! SDL_GetError: %s\n", SDL_GetError());
    }
    else {
        gWindow = SDL_CreateWindow("Slinx 0.0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            fprintf(stderr, "Window could not be created! SDL_GetError: %s\n", SDL_GetError());
        }
        else {
            // Make fullscreen
            SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN);
            // Now, this literally gets us the window surface so that we can modify it. We'll later return it back to the window in order to display it.
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

}

/**
    void mainWindow::loadGUI()

    Loads the menu labels and the background animation.
*/
void mainWindow::loadGUI() {

    gBackground = SDL_LoadBMP("inc/media/images/bg.bmp");
    if (gBackground == NULL) {
        fprintf(stderr, "SDL_LoadBMP(): Unable to load image! SDL_GetError: %s\n", SDL_GetError());
    }

    if (TTF_Init() != 0) {
        fprintf(stderr, "TTF_Init(): Failed to initialize the SDL TTF library. TTF_GetError(): %s", TTF_GetError());
    }

    TTF_Font *font;
    font = TTF_OpenFont("inc/media/fonts/Ubuntu-Title/Ubuntu-Title.ttf", 50);
    if (font == NULL) {
        fprintf(stderr, "TTF_OpenFont(): Failed to load main label fonts. TTF_GetError():  %s",  TTF_GetError());
    }

    SDL_Color text_color = {0, 0, 0};
    sTitle = TTF_RenderText_Solid(font, "Slinx", text_color);

    if (sTitle == NULL) {
        fprintf(stderr, "TTF_RenderText_Solid(): Failed to render TTF text. TTF_GetError(): %s", TTF_GetError());
    }
}

/**
    void mainWindow::close()

    Frees the used resources and closes SDL.
*/
void mainWindow::close() {
	SDL_FreeSurface(gBackground);
	gBackground = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

    TTF_Quit();
	SDL_Quit();
}

/**
    constructor mainWindow::mainWindow()

    Calls the member functions of mainWindow and ensures the gScreenSurface we
    got through SDL_GetWindowSurface gets back to the window updated.
*/
mainWindow::mainWindow(){
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;

    init();
	printf("Init - DONE.");
    loadGUI();
	printf("Load GUI - DONE.");
	//While application is running
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if ((e.type == SDL_QUIT) ||
				((e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_ESCAPE)))
			{
				quit = true;
			}
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym = SDLK_0)
				{
					// start obj loader
				}
			}
		}
		if (SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL) != 0) {
			fprintf(stderr, "SDL_BlitSurface(): Failed to apply background. SDL_GetError(): %s", SDL_GetError());
		}
		if (SDL_BlitSurface(sTitle, NULL, gScreenSurface, NULL) != 0) {
			fprintf(stderr, "SDL_BlitSurface(): Failed to apply title. SDL_GetError(): %s", SDL_GetError());
		}
		SDL_UpdateWindowSurface(gWindow);
	}
	if (quit)
	{
		close();
	}
    
}

mainWindow::~mainWindow() {}
