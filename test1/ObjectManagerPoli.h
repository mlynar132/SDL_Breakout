#pragma once

#include "GameObjectPoli.h"

#include "ObjectBall.h"
#include "ObjectBlock.h"
#include "ObjectPadle.h"
#include "ObjectPowerUp.h"

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
	void RemoveObject(GameObjectPoli* object);
private:
	std::vector<std::unique_ptr<GameObjectPoli>> objects;
};