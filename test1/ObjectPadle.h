#pragma once

#include <SDL.h>

#include "GameObjectPoli.h"
#include "TextureManager.h"

class ObjectPadle : public GameObjectPoli
{
public:
	ObjectPadle(int x, int y, const char* fileName);
	~ObjectPadle();
	void Update() override;
	void Render() override;
private:
	int x, y;
	SDL_Rect destRect;
	SDL_Texture* tex;
};