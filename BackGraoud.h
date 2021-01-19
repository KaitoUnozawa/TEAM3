#pragma once
#include "Player.h"

class BackGraoud {
private:
	int worldX, worldY;
	int scrollX, scrollY;
	//int posX;
	//int posY;
	//int moveX, moveY;
	int startX, startY;
	int moveFlag;
public:
	BackGraoud();
	int getMoveFlag();
	void update(char keys[255], char oldkeys[255], Player* player);
	void move(char keys[255], char oldkeys[255], Player* player);
	void draw();
};