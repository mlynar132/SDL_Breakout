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
	RemoveObject();
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

void ObjectManagerPoli::RemoveObject() {
	objects.erase(std::remove_if(objects.begin(), objects.end(), [](const std::unique_ptr<GameObjectPoli>& object) {return object->dead; }), objects.end());
	//std::remove(objects.begin(), objects.end(), object);
	//objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());// erase-remove idiom
}

void ObjectManagerPoli::CheckBallCollisionFor(GameObjectPoli* object, float radius) {
	for (int i = 0; i < objects.size(); i++) {
		bool col = true;
		if (!(objects[i]->center.x == object->center.x && objects[i]->center.y == object->center.y)) {//it would be better to do it with pointer comparison but also yeah 2 objects shouldn't have the same centers
			for (int j = 0; j < objects[i]->points.size(); j++) {
				int b = (j + 1) % objects[i]->points.size();
				Game::vec2d axisPro = { -(objects[i]->points[b].y - objects[i]->points[j].y), objects[i]->points[b].x - objects[i]->points[j].x };

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
				Game::vec2d NormalOfSurface;
				for (int j = 0; j < objects[i]->points.size(); j++) {
					int b = (j + 1) % objects[i]->points.size();
					if (Intersects(objects[i]->points[j], objects[i]->points[b], objects[i]->center, object->center))
					{/*
						std::cout << objects[i]->points[j].x << ' ' <<  objects[i]->points[j].y << ' ' << objects[i]->points[b].x << ' ' << objects[i]->points[b].y << '\n';
						SDL_SetRenderDrawColor(Game::renderer, 0, 250, 0, 255);
						SDL_RenderDrawLineF(Game::renderer, objects[i]->points[j].x, objects[i]->points[j].y, objects[i]->points[b].x, objects[i]->points[b].y);
						SDL_RenderPresent(Game::renderer);
						SDL_SetRenderDrawColor(Game::renderer, 50, 50, 50, 255);*/
						NormalOfSurface = { -(objects[i]->points[b].y - objects[i]->points[j].y), objects[i]->points[b].x - objects[i]->points[j].x };
						int MagOfNormal = sqrt((NormalOfSurface.x * NormalOfSurface.x) + (NormalOfSurface.y * NormalOfSurface.y));
						NormalOfSurface = { NormalOfSurface.x / MagOfNormal, NormalOfSurface.y / MagOfNormal };

					//	std::cout << NormalOfSurface.x << ' ' << NormalOfSurface.y << '\n';
						object->direction = { (NormalOfSurface.x * 2 * (-object->direction.x * NormalOfSurface.x + -object->direction.y * NormalOfSurface.y)) + object->direction.x, (NormalOfSurface.y * 2 * (-object->direction.x * NormalOfSurface.x + -object->direction.y * NormalOfSurface.y)) + object->direction.y };
					}
				}
				if (objects[i]->ObjectType == GameObjectPoli::Block)
				{
					//objects[i].release();
					//RemoveObject(objects[i].release());
					//objects.erase(std::remove(objects.begin(), objects.end(), objects[i]), objects.end());// erase-remove idiom
					//objects[i].reset();
					// 
					objects[i]->dead = true;
				//	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());// erase-remove idiom
				}
			}

		}

	}
	return;//true
}

bool ObjectManagerPoli::CheckForGameOver() {
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->ObjectType == GameObjectPoli::Ball)
		{
			return false;
		}
	}
	return true;
}

bool ObjectManagerPoli::Intersects(GameObjectPoli::vec2d A, GameObjectPoli::vec2d B, GameObjectPoli::vec2d X, GameObjectPoli::vec2d Y) {
	int	dx0 = B.x - A.x;
	int dx1 = Y.x - X.x;
	int	dy0 = B.y - A.y;
	int	dy1 = Y.y - X.y;
	int	p0 = dy1 * (Y.x - A.x) - dx1 * (Y.y - A.y);
	int	p1 = dy1 * (Y.x - B.x) - dx1 * (Y.y - B.y);
	int	p2 = dy0 * (B.x - X.x) - dx0 * (B.y - X.y);
	int	p3 = dy0 * (B.x - Y.x) - dx0 * (B.y - Y.y);
	return (p0 * p1 <= 0) && (p2 * p3 <= 0);
}