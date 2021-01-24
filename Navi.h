#pragma once
#include "Player.h"
#include "GameObject.h"
#include "Goal.h"
class Navi :public GameObject {
	int isAlive;
public:
	Navi();
	int GrHandle;
	float toGoalX;
	float toGoalY;
	float toGoalR;
	float radianX;
	float radianY;
	float PI;
	float angle;
	void update(int WIN_HEIGHT, int WIN_WIDTH, Player* player, Goal* goal);
	void indicate(int WIN_HEIGHT, int WIN_WIDTH, Player* player, Goal* goal);
	void visible(int WIN_HEIGHT, int WIN_WIDTH, Goal* goal);
	void draw();
};