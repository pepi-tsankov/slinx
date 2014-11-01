#include "inc/mainWindow.h"
#include "SDL_ttf.h"
#include <iostream>
#include <stdio.h>
#include <GL\glew.h>
#include <SDL_opengl.h>
//#include <GL\GLU.h>

SDL_Window* mainWindow::gWindow = NULL;
SDL_Surface* mainWindow::gScreenSurface = NULL;
SDL_Surface* mainWindow::gBackground = NULL;
SDL_Surface* mainWindow::sTitle = NULL;

SDL_Window *mainwindow; /* Our window handle */
SDL_GLContext maincontext; /* Our opengl context handle */

/* A simple function that prints a message, the error code returned by SDL,
* and quits the application */
void sdldie(const char *msg)
{
	printf("%s: %s\n", msg, SDL_GetError());
	SDL_Quit();
	exit(1);
}


void checkSDLError(int line = -1)
{
#ifndef NDEBUG
	const char *error = SDL_GetError();
	if (*error != '\0')
	{
		printf("SDL Error: %s\n", error);
		if (line != -1)
			printf(" + line: %i\n", line);
		SDL_ClearError();
	}
#endif
}


/**
    void mainWindow::init()

    Initializes SDL and thus the main window that contains the main game menu.

    TODO: center the window or pass FULLSCREEN parameter to SDL_CreateWindow
*/
//using namespace std;
void mainWindow::init() {
	

	if (SDL_Init(SDL_INIT_VIDEO) < 0) /* Initialize SDL's Video subsystem */
		sdldie("Unable to initialize SDL"); /* Or die on error */

	/*tell SDL that you want a forward compatible OpenGL 3.2 context*/
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);


	/* Create our window centered at 512x512 resolution */
	mainwindow = SDL_CreateWindow("SLINX", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(mainwindow);
}

/**
    void mainWindow::loadGUI()

    Loads the menu labels and the background animation.
*/
/*void mainWindow::loadGUI() {

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
}*/

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
    //loadGUI();
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
		/*if (SDL_BlitSurface(gBackground, NULL, gScreenSurface, NULL) != 0) {
			fprintf(stderr, "SDL_BlitSurface(): Failed to apply background. SDL_GetError(): %s", SDL_GetError());
		}
		if (SDL_BlitSurface(sTitle, NULL, gScreenSurface, NULL) != 0) {
			fprintf(stderr, "SDL_BlitSurface(): Failed to apply title. SDL_GetError(): %s", SDL_GetError());
		}
		SDL_UpdateWindowSurface(gWindow);*/
		SDL_GL_SwapWindow(mainwindow);
	}
	if (quit)
	{
		close();
	}
    
}

mainWindow::~mainWindow() {}
