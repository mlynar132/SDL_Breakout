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
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBall{ 250,400, "Assets/dude.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBall{250,400, "Assets/dude.png"});
	/*ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{{0,0,32,32}, "Assets/Block.png"});
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{ {34,0,32,32}, "Assets/Block.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{ {0,34,32,32}, "Assets/Block.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{ {34,34,32,32}, "Assets/Block.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{ {0,68,32,32}, "Assets/Block.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{ {34,68,32,32}, "Assets/Block.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{ {0,102,32,32}, "Assets/Block.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{ {34,102,32,32}, "Assets/Block.png" });*/
	ObjectManagerPoli::GetInstance().AddObject(new ObjectPadle{ 250,450, "Assets/dude.png" });
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
	std::cout << counter << '\n';
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