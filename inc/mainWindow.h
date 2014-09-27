#ifndef MAINWINDOW_H
	#define MAINWINDOW_H

	#include "SDL2/SDL.h"
	class mainWindow {
		public:
			mainWindow();
			~mainWindow();
		private:
			void init();
			void loadGUI();
			void close();
			static SDL_Window* gWindow;
			static SDL_Surface* gScreenSurface;
			static SDL_Surface* gBackground;
			static SDL_Surface* sTitle;
	};
#endif