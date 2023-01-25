#include "ObjectManagerPoli.h"



ObjectManagerPoli::ObjectManagerPoli() {

}

ObjectManagerPoli::~ObjectManagerPoli() {

}

ObjectManagerPoli& ObjectManagerPoli::GetInstance() {
	static ObjectManagerPoli instance;
	return instance;
}

void ObjectManagerPoli::UpdateObjects() {
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update();
	}
	std::cout << objects.size();
}

void ObjectManagerPoli::RenderObjects() {
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Render();
	}
}

void ObjectManagerPoli::AddObject(GameObjectPoli* object) {
	objects.emplace_back(object/*new ObjectBall{250,400, "Assets/dude.png"}*/);
}

void ObjectManagerPoli::RemoveObject(GameObjectPoli* object) {

}



/*
void ObjectMenagerPoli::UpdateObjects(std::vector<std::unique_ptr<GameObjectPoli>> objects) {
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update();
	}
}

void ObjectMenagerPoli::RenderObjects(std::vector<std::unique_ptr<GameObjectPoli>> objects) {
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Render();
	}
}

void ObjectMenagerPoli::AddToMenager(std::vector<std::unique_ptr<GameObjectPoli>> objects, GameObjectPoli* object) {

}

void ObjectMenagerPoli::RemoveFromMenager(std::vector<std::unique_ptr<GameObjectPoli>> objects, GameObjectPoli* object) {

}*/