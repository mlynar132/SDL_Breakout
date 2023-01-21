#include "Game.h"
#undef main // this fixes: Error	LNK2019	unresolved external symbol SDL_main referenced in function main_getcmdline	test1	C : \Work\Programming\C++\SDL\test1\test1\SDL2main.lib(SDL_windows_main.obj)	1


Game* game = nullptr;

int main(int argc, const char* argv[]) {

	const int fPS = 60;
	const int frameDelay = 1000 / fPS;
	Uint32 frameStart; //time at begining of frame
	int frameTime; //time after events update render etc.

	game = new Game();
	game->Init("DupeEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, false);

	while (game->Running()) {

		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart; 

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime); 
		}

	}

	game->Clean();
	
	return 0;
}



















































































/*#include "SDL.h"
#undef main
#include <iostream>


//don't do this, this is just an example
SDL_Renderer* renderer;
SDL_Window* window;
bool isRunning;
bool fullscreen;
void handleEvents();
void update();
void render();


//please don't put all your code in main like I did.
int main() {

	fullscreen = false;
	int flags = 0;
	flags = SDL_WINDOW_RESIZABLE;
	if (fullscreen) {
		flags = flags | SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!\n";

		window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, flags);
		if (window) {
			std::cout << "Window Created!\n";
			SDL_SetWindowMinimumSize(window, 100, 100);
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
			std::cout << "Renderer created!\n";
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			isRunning = true;
		}

	}

	while (isRunning) {
		handleEvents();
		update();
		render();
	}

	//frees memory associated with renderer and window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);	//error here
	SDL_Quit();


	return 0;
}

//handles any events that SDL noticed.
void handleEvents() {
	//the only event we'll check is the  SDL_QUIT event.
	SDL_Event event;
	SDL_PollEvent(&event);


	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

//simple render function
void render() {
	SDL_SetRenderDrawColor(renderer, 121, 121, 121, 255);
	SDL_RenderClear(renderer);

	//your stuff to render would typically go here.
	SDL_RenderPresent(renderer);
}

//simple update function
void update() {
	//if things could update the code would go in here.
}*/