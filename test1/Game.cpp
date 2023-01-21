#include "Game.h"
#include "TextureMenager.h"

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

Game::Game() {
 
}
Game::~Game() {

}

void Game::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized!...\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "window created!\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
			std::cout << "renderer created\n";
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	playerTex = TextureMenager::LoadTexture("Assets/dude.png", renderer);

}

void Game::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::Update() {
	counter++;
	destR.h = 16 * 2;
	destR.w = 16 * 2;
	destR.x = counter * 0.1;
	std::cout << counter << '\n';
}

void Game::Render() {
	SDL_RenderClear(renderer);	
	//this is where we would add stuff to render
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "GAME CLEANED\n";
}