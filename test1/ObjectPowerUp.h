#pragma once

#include <SDL.h>

#include "GameObjectPoli.h"
#include "TextureManager.h"

class ObjectPowerUp : public GameObjectPoli
{
public:
	ObjectPowerUp(int x, int y, const char* fileName);
	~ObjectPowerUp();
	void Update() override;
	void Render() override;
private:
	int x, y;
	SDL_Rect destRect;
	SDL_Texture* tex;
};