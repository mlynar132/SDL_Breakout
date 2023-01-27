#pragma once

#include <SDL.h>

#include "GameObjectPoli.h"
#include "TextureManager.h"

class ObjectBlock : public GameObjectPoli
{
public:
	ObjectBlock(SDL_Rect dest, const char* fileName);
	~ObjectBlock();
	void Update() override;
	void Render() override;
	void SetCenter() override;
	void SetPoints() override;
	void DebugMe() override;
private:
	SDL_Rect destRect;
	SDL_Texture* tex;
};