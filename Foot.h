#pragma once
#include"GameObject.h"
#include "Player.h"

class Foot {
private:
	float posX, posY, radius;
	int bright,isVisible;
public:
	Foot();
	int getIsVisible();
	void prepare(Player* player);
	void visible();
	void draw();
};