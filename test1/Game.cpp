#include "Game.h"
#include "ObjectBall.h"
#include "ObjectBlock.h"
#include "ObjectPadle.h"
#include "ObjectPowerUp.h"
#include "GameObjectPoli.h"
#include "ObjectManagerPoli.h"

SDL_Renderer* Game::renderer = nullptr;

//ObjectManagerPoli& dupa = ObjectManagerPoli::GetInstance();

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
	Level::LoadMap("Assets/TestFile1.txt", 2);
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBall{ 450,520,5,1, "Assets/Ball.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectPadle{ 450,552, "Assets/Padle.png" });
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
	ObjectManagerPoli::GetInstance().UpdateObjects();
}

void Game::Render() {
	SDL_RenderClear(renderer);	
	//this is where we would add stuff to render
	ObjectManagerPoli::GetInstance().RenderObjects();
	SDL_RenderPresent(renderer);
}

void Game::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "GAME CLEANED\n";
}