#include <string>
#include <fstream>
#include <queue>
#include <SDL.h>

#include "Level.h"
#include "ObjectManagerPoli.h"
#include "GameObjectPoli.h"

Level::Level() {

}

Level::~Level() {

}

void Level::LoadMap(const char* mapTxt, int spaces) {
	std::ifstream file;
	file.open(mapTxt);
	std::string temp;
	std::queue<std::string> buffer;
	int windowW;
	int windowH;//might wanna clean those
	SDL_GetRendererOutputSize(Game::renderer, &windowW, &windowH);
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBarierBlock{ {-10,0,10,windowH},"Assets/block.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBarierBlock{ {0,-10,windowW,10},"Assets/block.png" });
	ObjectManagerPoli::GetInstance().AddObject(new ObjectBarierBlock{ {windowW,0,10,windowH},"Assets/block.png" });

	windowH -= 100;
	while (file >> temp)
	{
		buffer.push(temp);
	}
	int bufferSizeStart = buffer.size();
	int h = (windowH - (bufferSizeStart - 1) * spaces) / bufferSizeStart;
	while (!buffer.empty())
	{
		temp = buffer.front();
		int w = (windowW - ((static_cast<int>(temp.size()) - 1)) * spaces) / static_cast<int>(temp.size());
		for (int i = 0; i < temp.size(); i++)
		{
			switch (temp[i])
			{
			case '0':
				break;
			case '1':
				ObjectManagerPoli::GetInstance().AddObject(new ObjectBlock{ {(w + spaces) * i,(h + spaces) * (bufferSizeStart - static_cast<int>(buffer.size())),w,h}, "Assets/block.png" });
				break;
			default:
				std::cout << "something wrong in level loading. Deafault case used";
				break;
			}
		}
		buffer.pop();
	}
}