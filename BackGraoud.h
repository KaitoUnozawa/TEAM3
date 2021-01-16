#pragma once
#include "Player.h"

class BackGraoud {
private:
	int posX;
	int posY;
	int moveX, moveY;
	int moveFlag;
public:
	int getMoveFlag();
	void update(Player* player);
	void move(Player* player);
	void draw();
};