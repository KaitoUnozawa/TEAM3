#include "Navi.h"
#include "Player.h"
#include "GameObject.h"
#include "Goal.h"
#include "DxLib.h"
#include "math.h"
#include "stdlib.h"

Navi::Navi() {
	this->posX = 0;
	this->posY = 0;
	isVisible = 1;
	GrHandle = LoadGraph("Resources/Navi.png");
	toGoalX = 0;
	toGoalY = 0;
	toGoalR = 0;
	radianX = 0;
	radianY = 0;
	PI = 3.14f;
	angle = PI / 2;
}
void  Navi::update(float WIN_HEIGHT, float WIN_WIDTH, Player* player, Goal* goal, Background* background) {
	indicate(WIN_HEIGHT, WIN_WIDTH, player, goal, background);
	visible(WIN_HEIGHT, WIN_WIDTH, goal);
}
void Navi::indicate(float WIN_HEIGHT, float WIN_WIDTH, Player* player, Goal* goal, Background* background) {
	//position
	float player2goalX = goal->getInitX() - (player->getPosX() + background->getScrollX());
	float player2goalY = goal->getInitY() - (player->getPosY() + background->getScrollY());
	float perX = fabs(player->getPosX() / player2goalX);
	float per = fabs(player->getPosY() / player2goalY);
	//goal->getInitX()- (player->getPosX() + background->getScrollX()) * (abs((WIN_HEIGHT - player->getPosY())/ player2goalY) )
	if (
		//ã
		goal->getPosY() < (WIN_HEIGHT / WIN_WIDTH) * goal->getPosX()
		&& goal->getPosY() < -(WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() + WIN_HEIGHT
		) {
		this->posX = player->getPosX() + player2goalX * per;
		this->posY = 30;
	} else if (
		//‰º
		goal->getPosY() > (WIN_HEIGHT / WIN_WIDTH) * goal->getPosX()
		&& goal->getPosY() > -(WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() + WIN_HEIGHT
		) {
		this->posX = goal->getPosX() + player2goalX * per;
		this->posY = 420;
	} else if (
		//¶
		goal->getPosY() > (WIN_HEIGHT / WIN_WIDTH) * goal->getPosX()
		&& goal->getPosY() < -(WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() + WIN_HEIGHT
		) {
		this->posX = 30;
		this->posY = player->getPosY() + player2goalY * perX;
	} else if (
		//‰E
		goal->getPosY() < (WIN_HEIGHT / WIN_WIDTH) * goal->getPosX()
		&& goal->getPosY() > -(WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() + WIN_HEIGHT
		) {
		this->posX = 770;
		this->posY = player->getPosY() + player2goalY * perX;
	}
	if (posX > 770) {
		this->posX = 770;
	}
	if (posX < 30) {
		this->posX = 30;
	}
	if (posY > 420) {
		this->posY = 420;
	}
	if (posY < 30) {
		this->posY = 30;
	}

	// angle
	toGoalX = (posX - goal->getPosX());
	toGoalY = (posY - goal->getPosY());
	toGoalR = (double)sqrt(pow(toGoalX, 2) + pow(toGoalY, 2));
	radianX = (double)cos(angle);
	radianY = (double)sin(angle);
	if (toGoalX * radianX + toGoalY * radianY < 0) {
		angle = angle + (PI / 90);
	} else if (toGoalX * radianX + toGoalY * radianY < 45) {
		angle = angle;
	} else {
		angle = angle - (PI / 90);
	}
}

void  Navi::visible(float WIN_HEIGHT, float WIN_WIDTH, Goal* goal) {
	if ((goal->getPosX() - goal->getRadius() < WIN_WIDTH) &&
		(goal->getPosY() - goal->getRadius() < WIN_HEIGHT) &&
		(goal->getPosX() + goal->getRadius() > 0) &&
		(goal->getPosY() + goal->getRadius() > 0)
		) {
		isVisible = 0;
	} else {
		isVisible = 1;
	}
}

void  Navi::draw() {
	DrawLine(0, 0, 800, 450, GetColor(255, 0, 0), TRUE);
	DrawLine(0, 450, 800, 0, GetColor(0, 0, 255), TRUE);
	if (isVisible == 1) {
		DrawRotaGraph((int)posX, (int)posY, 0.25f, angle, GrHandle, TRUE, TRUE);
	}
}