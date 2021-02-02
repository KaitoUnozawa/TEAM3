#pragma once
#include"GameObject.h"
#include "DxLib.h"

class Enemy;
class Background;
class Shake;
class Easing;

class Player :public GameObject {
private:
	float speed;
	float attackX, attackY, readyR, attackR;
	float effectX;
	float effectY;
	float effectR;
	float priPos;
	int pal;
	int isAlive, isAttack, isMove;
	int hpSize;
	float frameMax;
	int padCheack;
	int hp;
public:
	Player(float radius, float speed);
	~Player();

	float getPosX();
	float getPosY();
	float getRadius();
	float getSpeed();
	float getAttackX();
	float getAttackY();
	float getAttackR();
	int getIsAttack();
	int getIsAlive();
	int getHp();

	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
	void setSpeed(float speed);
	void setIsAttack(int isAttack);

	void update(Enemy* enemy, Background* background, Easing* easing, char keys[255], char oldkeys[255],XINPUT_STATE* input, int WIN_WIDTH);
	void move(char keys[255], char oldkeys[255], XINPUT_STATE* input, int WIN_WIDTH);
	void create();
	void collide(Enemy* enemy);
	void enclose(Easing* easing);
	void hitPointMove(Enemy* enemy, Background* background);
	void draw(Enemy* enemy, Shake* shake);
	void drawEffect();

};

