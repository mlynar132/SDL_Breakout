#include "ObjectPowerUp.h"

ObjectPowerUp::ObjectPowerUp(int x, int y, const char* fileName)
	:x(x), y(y)
{
	destRect.x = ObjectPowerUp::x;
	destRect.y = ObjectPowerUp::y;
	destRect.w = 16 * 2;
	destRect.h = 16 * 2;

	tex = TextureManager::LoadTexture(fileName);
}

void ObjectPowerUp::Update() {
	std::cout << "dsau\n";
}

void ObjectPowerUp::Render() {
	SDL_SetTextureColorMod(tex, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
}