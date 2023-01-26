#include "ObjectBall.h"

ObjectBall::ObjectBall(float x, float y, float radius, float speed, const char* fileName)
	:x(x), y(y), speed(speed)
{
	destRect.x = ObjectBall::x;
	destRect.y = ObjectBall::y;
	destRect.w = 16 * 2;
	destRect.h = 16 * 2;
	tex = TextureManager::LoadTexture(fileName);
	direction = RandomStartDirection();
}

void ObjectBall::Update() {
	x += direction.x * speed;
	destRect.x = x;
	y -= direction.y * speed;
	destRect.y = y;
}

void ObjectBall::Render() {
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
}

float ObjectBall::Magnitude(vec2d vec) {
	return sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

ObjectBall::vec2d ObjectBall::Normalize(vec2d vec) {
	float mag = Magnitude(vec);
	return vec2d{ vec.x / mag, vec.y / mag };
}

ObjectBall::vec2d ObjectBall::RandomStartDirection(){
	srand((unsigned int)time(NULL));
	direction.x = (rand() % 10) + 1;
	direction.y = (rand() % 10) + 1;
	if (rand() % 2 != 0)
	{
		direction.x *= -1;
	}
	return Normalize(direction);
}
