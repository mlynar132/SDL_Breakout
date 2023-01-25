#pragma once

#include <SDL.h>
#include "TextureManager.h"

class GameObject {

public:
	GameObject(int x, int y, const char* fileName);
	~GameObject();

	void Update();
	void Render();

private:
	int x, y;
	SDL_Rect destRect;
	SDL_Texture* tex;
};