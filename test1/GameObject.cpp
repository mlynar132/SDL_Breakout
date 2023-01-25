#include "GameObject.h"

GameObject::GameObject(int x, int y, const char* fileName)
	:x(x), y(y)
{
	destRect.x = GameObject::x;
	destRect.y = GameObject::y;
	destRect.w = 16 * 2;
	destRect.h = 16 * 2;
	tex = TextureManager::LoadTexture(fileName);
}

void GameObject::Update() {
	//destRect.x += 1;
	destRect.y += 1;
}

void GameObject::Render() {
	SDL_SetTextureColorMod(tex, 0, 0, 150);
	SDL_RenderCopy(Game::renderer, tex, NULL, &destRect);
}