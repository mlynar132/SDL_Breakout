#include "ObjectPaddle.h"

ObjectPaddle::ObjectPaddle(int x, int y, const char* fileName)
	:x(x), y(y)
{
	destRect.x = ObjectPaddle::x;
	destRect.y = ObjectPaddle::y;
	destRect.w = 16 * 2;
	destRect.h = 16 * 2;
	tex = TextureManager::LoadTexture(fileName);
}

void ObjectPaddle::Update() {
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

void ObjectPaddle::Render() {
	SDL_SetTextureColorMod(tex, 255, 255, 255);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
} 