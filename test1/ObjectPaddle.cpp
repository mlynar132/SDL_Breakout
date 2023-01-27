#include "ObjectPaddle.h"

ObjectPaddle::ObjectPaddle(int x, int y, const char* fileName)
	:x(x), y(y)
{
	ObjectType = Paddle;

	destRect.x = ObjectPaddle::x;
	destRect.y = ObjectPaddle::y;
	destRect.w = 16 * 2;
	destRect.h = 16 * 2;
	tex = TextureManager::LoadTexture(fileName);

	SetCenter();
	SetPoints();
}

void ObjectPaddle::Update() {
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_A])
	{
		destRect.x -= 1;
		SetCenter();
		SetPoints();
	}
	if (state[SDL_SCANCODE_D])
	{
		destRect.x += 1;
		SetCenter();
		SetPoints();
	}
}

void ObjectPaddle::Render() {
	SDL_SetTextureColorMod(tex, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
} 
void ObjectPaddle::SetCenter() {
	center.x = destRect.x + destRect.w / 2;
	center.y = destRect.y + destRect.h / 2;
}

void ObjectPaddle::SetPoints() {
	points.clear();
	points.push_back(vec2d{ static_cast<float>(destRect.x),static_cast<float>(destRect.y) });
	points.push_back(vec2d{ static_cast<float>(destRect.x + destRect.w),static_cast<float>(destRect.y) });
	points.push_back(vec2d{ static_cast<float>(destRect.x + destRect.w),static_cast<float>(destRect.y + destRect.h) });
	points.push_back(vec2d{ static_cast<float>(destRect.x),static_cast<float>(destRect.y + destRect.h) });
	//padle doesnt have points
	//might wanna do this with ints to avoid casting
}

void ObjectPaddle::DebugMe() {
	SDL_RenderClear(Game::renderer);
	SDL_Rect nah;
	nah.x = destRect.x;
	nah.y = destRect.y;
	nah.w = destRect.w + 10;
	nah.h = destRect.h + 10;
	SDL_SetRenderDrawColor(Game::renderer, 0, 200, 0, 255);
	SDL_RenderDrawRect(Game::renderer, &nah);
	SDL_SetRenderDrawColor(Game::renderer, 50, 50, 50, 255);
	SDL_RenderPresent(Game::renderer);
}