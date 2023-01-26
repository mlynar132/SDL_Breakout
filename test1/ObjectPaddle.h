#pragma once

#include <SDL.h>

#include "GameObjectPoli.h"
#include "TextureManager.h"

class ObjectPaddle : public GameObjectPoli
{
public:
	ObjectPaddle(int x, int y, const char* fileName);
	~ObjectPaddle();
	void Update() override;
	void Render() override;
private:
	int x, y;
	SDL_Rect destRect;
	SDL_Texture* tex;
};