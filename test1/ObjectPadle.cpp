#include "ObjectPadle.h"

ObjectPadle::ObjectPadle(int x, int y, const char* fileName)
	:x(x), y(y)
{
	destRect.x = ObjectPadle::x;
	destRect.y = ObjectPadle::y;
	destRect.w = 16 * 2;
	destRect.h = 16 * 2;
	tex = TextureManager::LoadTexture(fileName);
}

void ObjectPadle::Update() {
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_A])
	{
		destRect.x -= 1;
	}
	if (state[SDL_SCANCODE_D])
	{
		destRect.x += 1;
	}
}

void ObjectPadle::Render() {
	SDL_SetTextureColorMod(tex, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
} 