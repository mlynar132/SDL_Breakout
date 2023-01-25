#include <string>
#include <fstream>
#include <queue>
#include <SDL.h>

#include "Level.h"
#include "ObjectManagerPoli.h"
#include "GameObjectPoli.h"

//ObjectManagerPoli& dupa = ObjectManagerPoli::GetInstance();

Level::Level() {

}

Level::~Level() {

}
//void Level::LoadMap(char* mapTxt) {
	/*std::ifstream file;
file.open("Assets/TestFile1.txt");
std::string temp;
while (file >> temp)
{
	for (int i = 0; i < temp.size(); i++)
	{
		std::cout << temp[i];
		GameObject* lol = new GameObject(0, 0, "Assets/block.png");
	//	GameObject lol(0, 0, "Assets/block.png");
		/*switch (temp[i])
		{
		case 0:
			break;
		case 1:
			GameObject lol(0, 0, "Assets/block.png");
			break;
		default:
			break;
		}
	}
	std::cout << '\n';
}*/
//}

void Level::LoadMap(const char* mapTxt, int spaces) {
	std::ifstream file;
	file.open(mapTxt);
	std::string temp;
	std::queue<std::string> buffer;
	int windowW;
	int windowH;//might wanna clean those
	SDL_GetRendererOutputSize(Game::renderer, &windowW, &windowH);
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