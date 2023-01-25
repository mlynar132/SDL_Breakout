#include "ObjectBall.h"

ObjectBall::ObjectBall(int x, int y, const char* fileName)
	:x(x), y(y)
{
	destRect.x = ObjectBall::x;
	destRect.y = ObjectBall::y;
	destRect.w = 16 * 2;
	destRect.h = 16 * 2;
	tex = TextureManager::LoadTexture(fileName);
}

void ObjectBall::Update() {
	//destRect.x += 1;
	destRect.y -= 1;
}

void ObjectBall::Render() {
	SDL_SetTextureColorMod(tex, 0, 150, 0);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
	/*SDL_SetRenderDrawColor(Game::renderer, 150, 0, 150, 255);
	SDL_RenderDrawRect(Game::renderer, &destRect);
	SDL_SetRenderDrawColor(Game::renderer, 50, 50, 50, 255);*/
}