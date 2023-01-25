#pragma once

#include "GameObjectPoli.h"
#include "TextureManager.h"

class ObjectBall : public GameObjectPoli
{
public:
	ObjectBall(int x, int y, const char* fileName);
	~ObjectBall();
	void Update() override;
	void Render() override;
private:
	int x, y;
	SDL_Rect destRect;
	SDL_Texture* tex;
};