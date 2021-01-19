#pragma once
#include"GameObject.h"
class Goal :public GameObject {
	int isAlive;
	int image;
public:
	Goal();
	void update(int WIN_WIDTH, int WIN_HEIGHT, char keys[256]);
	void draw();
	void create(int WIN_WIDTH, int WIN_HEIGHT, char keys[256]);
	float getPosX();
	float getPosY();
	float getRadius();
	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
};

