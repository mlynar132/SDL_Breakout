#pragma once

class ObjectMenager {
	ObjectMenager();
	~ObjectMenager();

public:
	//static void UpdateObjects();
	//static void RenderObjects();
//	static void AddToMenager(GameObject object);
	//static void DeleteFromMenager(GameObject object);
private:
	//std::vector<std::unique_ptr<GameObject>> objects;
	//I'm using vector cus I'm going to add/remove elemnts (so no array) but not hashset since it's more important to iterate throught every object 
};