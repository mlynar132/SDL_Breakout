#pragma once

class GameObjectPoli {

public:
	GameObjectPoli();
	~GameObjectPoli();
	virtual void Update() = 0;
	virtual void Render() = 0;
private:
	//int x, y;
	//SDL_Rect destRect;
	//SDL_Texture* tex;
};

