#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>

#include "Level.h"

class GameObjectPoli;

class Game{

public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void HandleEvents();
	void Update();
	void Render();
	void Clean();
	
	bool Running() { return isRunning; }

	static SDL_Renderer* renderer;

	struct vec2d {
		float x;
		float y;
	};
private:
	int counter = 0;
	bool isRunning;
	SDL_Window* window;
};