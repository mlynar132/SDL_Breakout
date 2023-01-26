#include "ObjectBlock.h"

ObjectBlock::ObjectBlock(SDL_Rect dest, const char* fileName)
	:destRect(dest)
{
	center.x = destRect.x + destRect.w / 2;
	center.y = destRect.y + destRect.h / 2;

	points.push_back(vec2d{static_cast<float>(destRect.x),static_cast<float>(destRect.y) });
	points.push_back(vec2d{ static_cast<float>(destRect.x + destRect.w),static_cast<float>(destRect.y) });
	points.push_back(vec2d{ static_cast<float>(destRect.x + destRect.w),static_cast<float>(destRect.y + destRect.h) });
	points.push_back(vec2d{ static_cast<float>(destRect.x),static_cast<float>(destRect.y + destRect.h) });
	//might wanna do this with ints to avoid casting
	
	tex = TextureManager::LoadTexture(fileName);
}

void ObjectBlock::Update() {

}

void ObjectBlock::Render() {
	SDL_SetTextureColorMod(tex, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
	/* draw blocks with lines
	SDL_SetRenderDrawColor(Game::renderer, 0, 200, 0, 255);
	for (int i = 0; i < 3; i++)
	{
		SDL_RenderDrawLineF(Game::renderer, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
	}
	SDL_RenderDrawLineF(Game::renderer, points[3].x, points[3].y, points[0].x, points[0].y);
	SDL_SetRenderDrawColor(Game::renderer, 50, 50, 50, 255);*/
}