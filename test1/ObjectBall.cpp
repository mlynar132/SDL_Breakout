#include "ObjectBall.h"

ObjectBall::ObjectBall(float x, float y, float radius, float speed, const char* fileName)
	:x(x), y(y), radius(radius), speed(speed)
{
	ObjectType = Ball;

	destRect.x = ObjectBall::x;
	destRect.y = ObjectBall::y;
	destRect.w = 16 * 2;
	destRect.h = 16 * 2;
	SetCenter();
	SetPoints();

	tex = TextureManager::LoadTexture(fileName);
	direction = RandomStartDirection();
}

void ObjectBall::Update() {
	ObjectManagerPoli::GetInstance().CheckBallCollisionFor(this, radius);
	if (center.y > 600 + radius)
	{
		dead = true;
		//delete this;
		//ObjectManagerPoli::GetInstance().RemoveObject()
	}
	//x += direction.x * speed;
	center.x += direction.x * speed;
	destRect.x = center.x - radius;
	//center.x = x;
	//y -= direction.y * speed;
	center.y -= direction.y * speed;
	destRect.y = center.y - radius;
}

void ObjectBall::Render() {
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
	SDL_SetRenderDrawColor(Game::renderer, 0, 255, 0, 255);
	SDL_RenderDrawLineF(Game::renderer, center.x, center.y, center.x + direction.x * speed * 50, center.y - direction.y * speed * 50);
	//std::cout << center.x << ' ' << center.y << ' ' << center.x + direction.x * speed * 50 << ' ' << center.y - direction.y * speed * 50 << '\n';
	SDL_SetRenderDrawColor(Game::renderer, 50, 50, 50, 255);
}

float ObjectBall::Magnitude(vec2d vec) {
	return sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

ObjectBall::vec2d ObjectBall::Normalize(vec2d vec) {
	float mag = Magnitude(vec);
	return vec2d{ vec.x / mag, vec.y / mag };
}

GameObjectPoli::vec2d ObjectBall::RandomStartDirection() {
	srand((unsigned int)time(NULL));
	direction.x = (rand() % 10) + 1;
	direction.y = (rand() % 10) + 1;
	if (rand() % 2 != 0)
	{
		direction.x *= -1;
	}
	return Normalize(direction);
}

void ObjectBall::SetCenter() {
	center.x = destRect.x + destRect.w / 2;
	center.y = destRect.y + destRect.h / 2;
}

void ObjectBall::SetPoints() {
	points.push_back(center);
}

void ObjectBall::DebugMe() {
	SDL_Rect nah;
	nah.x = destRect.x;
	nah.y = destRect.y;
	nah.w = destRect.w + 10;
	nah.h = destRect.h + 10;
	SDL_SetRenderDrawColor(Game::renderer, 0, 200, 0, 255);
	SDL_RenderDrawRect(Game::renderer, &nah);
	SDL_SetRenderDrawColor(Game::renderer, 50, 50, 50, 255);
}