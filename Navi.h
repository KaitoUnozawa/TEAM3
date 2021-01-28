#pragma once
#include "Player.h"
#include "GameObject.h"
#include "Goal.h"
#include "Background.h"

class Navi :public GameObject {
	int isVisible;
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
	void update(float WIN_HEIGHT, float WIN_WIDTH, Player* player, Goal* goal, Background* background);
	void indicate(float WIN_HEIGHT, float WIN_WIDTH, Player* player, Goal* goal, Background* background);
	void visible(float WIN_HEIGHT, float WIN_WIDTH, Goal* goal);
	void draw();
};