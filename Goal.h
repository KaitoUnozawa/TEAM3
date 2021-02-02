#pragma once
#include"GameObject.h"
#include "Background.h"
class Shake;
class Player;
class Enemy;
class Color;
class Goal :public GameObject {
	float initX, initY;
	int isAlive, isClear, isCollect;
	int image;
	int R, B, G;
	double gauge;

	int efRadius;
	float priPos;
	int pal;
public:
	Goal();
	void update(int WIN_WIDTH, int WIN_HEIGHT, Background* backgraund, Player* player, Enemy* enemy);
	void draw(Shake* shake, Color* color);
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
	void collide(Player* player, Enemy* enemy);
};

