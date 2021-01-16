#pragma once
#include"GameObject.h"
#include "Player.h"
#include "BackGraoud.h"

class Enemy :public GameObject {
public:
	float speed;
	int isAlive;
public:
	Enemy(float radius, float speed, int isAlive);
	~Enemy();

	void update(Player* player, BackGraoud* backgraoud, char keys[255], char oldkeys[255]);
	void draw();
	void move(Player* player, BackGraoud* backgraoud);
	void collide(Player* player, char keys[255], char oldkeys[255]);
	float getPosX();
	float getPosY();
	float getRadius();
	float getSpeed();

	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
	void setSpeed(float speed);
	void setIsAlive(int isAlive);
};