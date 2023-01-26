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
	struct vec2d//might wanna do this with ints to avoid casting
	{
		float x;
		float y;
	};
	vec2d center;
	std::vector<vec2d> points;
private:
	SDL_Rect destRect;
	SDL_Texture* tex;
};