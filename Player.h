#pragma once
#include <vector>
#include"GameObject.h"

class Enemy;
class BackGraoud;

using namespace std;

class Player :public GameObject {
private:
	float speed;
	float attackX, attackY, readyR, attackR;
	int isAlive, isAttack, isMove;
	int hpSize;
public:
	// 配列のアクセッサの取り方が分からなかったので仕方なくです。禁忌かもですがゆるせ
	vector<int> hitPoint;
	vector<float> hitPointX;
	vector<float> hitPointY;

	Player(float posX, float posY, float radius, float speed);
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
	int getIsMove();

	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
	void setSpeed(float speed);
	void setIsAttack(int isAttack);

	void update(BackGraoud* backgraoud, char keys[255], char oldkeys[255], int WIN_WIDTH);
	void move(char keys[255], char oldkeys[255], int WIN_WIDTH);
	void create();
	void enclose();
	void hitPointMove(BackGraoud* backgraoud);
	void draw();
};

