#pragma once
#include <vector>
#include "GameObject.h"
#include "Background.h"

class Player;
class Shake;

using namespace std;

class Enemy :public GameObject {
private:
	float initX, initY;
	float speed;
	int isAlive;
	int isFollow;
	int isRespawn;
	int count;
	vector<int> hitPoint;
	vector<float> hitPointX;
	vector<float> hitPointY;
	vector<float>::iterator itX;
	vector<float>::iterator itY;
	/*int hitPoint;
	float hitPointX[50] = { 0 };
	float hitPointY[50] = { 0 };*/
	float hpXBuf;
	float hpYBuf;
	int push;
public:
	Enemy(float radius, float speed, int isAlive);
	~Enemy();

	float getPosX();
	float getPosY();
	float getRadius();
	float getSpeed();
	int getIsAlive();
	int getHitPointSize();
	float getHitPointX();
	float getHitPointY();

	void setPosX(float posX);
	void setPosY(float posY);
	void setRadius(float radius);
	void setSpeed(float speed);
	void setIsAlive(int isAlive);
	void setHitPoint(int hitPoint);
	void setHitPointX(int hitPointX);
	void setHitPointY(int hitPointY);

	void addHitPoint(int index);
	void subHitPoint(int index);

	void arrayToObject(int index);
	void ObjectToArray(int index);

	void update(Enemy* enemy, Player* player, Shake* shake, Background* background, char keys[255], char oldkeys[255]);
	void move(Player* player, Background* background);
	void collide(Enemy* enemy, Player* player, Shake* shake, char keys[255], char oldkeys[255]);
	void respawn(Background* background);

	void draw(Shake* shake);
};