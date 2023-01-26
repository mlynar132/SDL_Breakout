#pragma once

#include "GameObjectPoli.h"
#include "TextureManager.h"

class ObjectBall : public GameObjectPoli
{
public:
	ObjectBall(float x, float y, float radius, float speed, const char* fileName);
	~ObjectBall();
	void Update() override;
	void Render() override;
private:
	struct vec2d
	{
		float x;
		float y;
	};
	float x, y;
	float radius;
	vec2d direction;
	float speed;
	float Magnitude(vec2d vec);
	vec2d Normalize(vec2d vec);
	vec2d RandomStartDirection();
	SDL_Rect destRect;
	SDL_Texture* tex;
};