#pragma once

class Level {
	Level();
	~Level();
	
public:
	static void LoadMap(const char* mapTxt, int spaces);
private:
	char* map;
};
