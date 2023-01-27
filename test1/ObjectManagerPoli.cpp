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

void ObjectManagerPoli::CheckBallCollisionFor(GameObjectPoli* object, float radius) {
	for (int i = 0; i < objects.size(); i++) {
		bool col = true;
		if (!(objects[i]->center.x == object->center.x && objects[i]->center.y == object->center.y)) {//it would be better to do it with pointer comparison but also yeah 2 objects shouldn't have the same centers
			for (int j = 0; j < objects[i]->points.size(); j++) {
				int b = (j + 1) % objects[i]->points.size();
				Game::vec2d axisPro = { -(objects[i]->points[b].y - objects[i]->points[j].y), objects[i]->points[b].x - objects[i]->points[j].x};
				
				float min2 = INFINITY;
				float max2 = -INFINITY;
				float q;
				for (int k = 0; k < objects[i]->points.size(); k++)
				{
					q = objects[i]->points[k].x * axisPro.x + objects[i]->points[k].y * axisPro.y;
					min2 = std::min(min2, q);
					max2 = std::max(max2, q);
				}
				float min1 = INFINITY;
				float max1 = -INFINITY;
				
				q = (object->center.x + radius) * axisPro.x + (object->center.y + radius) * axisPro.y;
				min1 = std::min(min1, q);
				max1 = std::max(max1, q);

				q = (object->center.x - radius) * axisPro.x + (object->center.y - radius) * axisPro.y;
				min1 = std::min(min1, q);
				max1 = std::max(max1, q);

				if (!(max2 >= min1 && max1 >= min2)) {
					col = false;
					break;
				}
			}
			if (col) {
			delete& objects[i];
			//objects[i]->DebugMe();
			std::cout << 'n';
			}
			
		}

	}
	return;//true
}