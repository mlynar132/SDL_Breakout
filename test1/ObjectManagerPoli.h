#pragma once

#include "GameObjectPoli.h"

#include "ObjectBall.h"
#include "ObjectBlock.h"
#include "ObjectPaddle.h"
#include "ObjectPowerUp.h"
#include "ObjectBarierBlock.h"

class ObjectManagerPoli {
protected:
	ObjectManagerPoli();
public:
	~ObjectManagerPoli();
	ObjectManagerPoli(const ObjectManagerPoli&) { std::cout << "you are trying to use a copy constructor on a singletion fix it or you will get bugs\n"; };
	ObjectManagerPoli(ObjectManagerPoli&&) { std::cout << "you are trying to use a move constructor on a singletion fix it or you will get bugs\n"; };
	ObjectManagerPoli& operator= (const ObjectManagerPoli&) { std::cout << "you are trying to use a copy asign operator on a singletion fix it or you will get bugs\n"; };
	ObjectManagerPoli& operator= (ObjectManagerPoli&&) { std::cout << "you are trying to use a move asign operator on a singletion fix it or you will get bugs\n"; };
	static ObjectManagerPoli& GetInstance();
	void UpdateObjects();
	void RenderObjects();
	void AddObject(GameObjectPoli* object);
	void RemoveObject();
	void CheckBallCollisionFor(GameObjectPoli* object, float radius);
	bool CheckForGameOver();
private:
	std::vector<std::unique_ptr<GameObjectPoli>> objects;
	bool Intersects(GameObjectPoli::vec2d A, GameObjectPoli::vec2d B, GameObjectPoli::vec2d X, GameObjectPoli::vec2d Y);
};