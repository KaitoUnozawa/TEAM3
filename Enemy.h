#pragma once
#include "GameObject.h"
#include "BackGraoud.h"

class Player;

class Enemy :public GameObject {
public:
	float initX, initY;
	float speed;
	int isAlive;
	int isFollow;
public:
	Enemy(float radius, float speed, int isAlive);
	~Enemy();

	float getPosX();
	float getPosY();
	float getRadius();
	float getSpeed();
	int getIsAlive();

	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
	void setSpeed(float speed);
	void setIsAlive(int isAlive);

	void update(Player* player, BackGraoud* backgraoud, char keys[255], char oldkeys[255]);
	void move(Player* player, BackGraoud* backgraoud);
	void collide(Player* player, char keys[255], char oldkeys[255]);

	void draw();
};