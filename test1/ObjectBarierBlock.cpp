#include "ObjectBarierBlock.h"

ObjectBarierBlock::ObjectBarierBlock(SDL_Rect dest, const char* fileName)
	:destRect(dest)
{
	ObjectType = BarierBlock;

	SetCenter();
	SetPoints();

	tex = TextureManager::LoadTexture(fileName);
}

void ObjectBarierBlock::Update() {

}

void ObjectBarierBlock::Render() {
	SDL_SetTextureColorMod(tex, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
	SDL_Rect nah;
	nah.x = destRect.x;
	nah.y = destRect.y;
	nah.w = destRect.w + 10;
	nah.h = destRect.h + 10;
}

void ObjectBarierBlock::SetCenter() {
	center.x = destRect.x + destRect.w / 2;
	center.y = destRect.y + destRect.h / 2;
}

void ObjectBarierBlock::SetPoints() {
	points.push_back(vec2d{ static_cast<float>(destRect.x),static_cast<float>(destRect.y) });
	points.push_back(vec2d{ static_cast<float>(destRect.x + destRect.w),static_cast<float>(destRect.y) });
	points.push_back(vec2d{ static_cast<float>(destRect.x + destRect.w),static_cast<float>(destRect.y + destRect.h) });
	points.push_back(vec2d{ static_cast<float>(destRect.x),static_cast<float>(destRect.y + destRect.h) });
	//might wanna do this with ints to avoid casting
}
void ObjectBarierBlock::DebugMe() {
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