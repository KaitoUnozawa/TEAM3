#pragma once
#include"GameObject.h"
#include "Background.h"
#include "Player.h"
class Shake;
class Goal :public GameObject {
	float initX, initY;
	int isAlive, isClear;
	int image;
	int R, B, G;
	double gauge;
public:
	Goal();
	void update(int WIN_WIDTH, int WIN_HEIGHT, Background* backgraund, Player* player);
	void draw(Shake* shake);
	void create(int WIN_WIDTH, int WIN_HEIGHT, Background* backgraund);
	int getIsClear();
	float getPosX();
	float getPosY();
	float getRadius();
	float getInitX();
	float getInitY();
	void setIsClear(int isClear);
	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
	void collide(Player* player);
};

