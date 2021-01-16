#pragma once
#include"GameObject.h"

class Player :public GameObject {
private:
	float speed;
	float attackX, attackY, readyR, attackR;
	int isAlive, isAttack;
public:
	Player(float posX, float posY, float radius, float speed);
	~Player();

	void update(char keys[255], char oldkeys[255], int WIN_WIDTH);
	void draw();
	void move(char keys[255], char oldkeys[255], int WIN_WIDTH);
	void create();
	void enclose();
	float getPosX();
	float getPosY();
	float getRadius();
	float getSpeed();
	float getAttackX();
	float getAttackY();
	float getAttackR();
	int getIsAttack();
	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
	void setSpeed(float speed);
	void setIsAttack(int isAttack);
};

