#ifndef MAINWINDOW_H
	#define MAINWINDOW_H

	#include "SDL2/SDL.h"
	class mainWindow
	{
		public:
			mainWindow();
		private:
			bool init();
			bool loadBackground();
			void close();
			static SDL_Window* gWindow;
			static SDL_Surface* gScreenSurface;
			static SDL_Surface* gBackground;
	};
#endif
