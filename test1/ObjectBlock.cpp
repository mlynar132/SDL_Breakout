#include "ObjectBlock.h"

ObjectBlock::ObjectBlock(SDL_Rect dest, const char* fileName)
	:destRect(dest)
{
	/*
	destRect.x = ObjectBlock::x;
	destRect.y = ObjectBlock::y;
	destRect.w = w;
	destRect.h = h;//you can't do :destRect.h(h)*/
	tex = TextureManager::LoadTexture(fileName);
}

void ObjectBlock::Update() {

}

void ObjectBlock::Render() {
	SDL_SetTextureColorMod(tex, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
}