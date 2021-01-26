#pragma once
#include "Player.h"
//#include "Easing.h"

class BackGraoud {
private:
	float worldX, worldY;
	float scrollX, scrollY;
	int startX, startY;
	int moveFlag;
public:
	BackGraoud();
	float getWorldX();
	float getWorldY();
	float getScrollX();
	float getScrollY();
	int getMoveFlag();
	void update(char keys[255], char oldkeys[255], Player* player);
	void move(char keys[255], char oldkeys[255], Player* player);
	void draw();
};