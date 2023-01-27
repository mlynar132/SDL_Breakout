#pragma once

#include "vector"

class GameObjectPoli {

public:
	GameObjectPoli();
	~GameObjectPoli();
	virtual void Update() = 0;
	virtual void Render() = 0;
	struct vec2d
	{
		float x;
		float y;
	};
	vec2d center;
	std::vector<vec2d> points;
	virtual void SetCenter() = 0;
	virtual void SetPoints() = 0;
	virtual void DebugMe() = 0;
private:

	//int x, y;
	//SDL_Rect destRect;
	//SDL_Texture* tex;
};

