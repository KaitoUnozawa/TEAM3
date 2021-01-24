#pragma once
#include"GameObject.h"
#include "BackGraoud.h"
#include "Player.h"
class Goal :public GameObject {
	int isAlive;
	int image;
	int R, B, G;
	double gauge;
public:
	Goal();
	void update(int WIN_WIDTH, int WIN_HEIGHT, BackGraoud* backgraund, Player* player);
	void draw();
	void create(int WIN_WIDTH, int WIN_HEIGHT, BackGraoud* backgraund);
	float getPosX();
	float getPosY();
	float getRadius();
	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
	void collide(Player* player);
};

