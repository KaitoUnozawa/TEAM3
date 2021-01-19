#include "Navi.h"
#include "Player.h"
#include"GameObject.h"
#include "Goal.h"
#include <DxLib.h>
#include"math.h"
Navi::Navi(){
	isAlive = 1;
	player2goalX=0;
	player2goalY=0;
	player2goalR=0;
	perX=0;
	perY=0;
	GrHandle= LoadGraph("Resources/Navi.png");
	toGoalX=0;
	toGoalY=0;
	toGoalR=0;
	radianX=0;
	radianY=0;
	PI = 3.14f;
	angle = PI / 2;
}
void  Navi::update(int WIN_HEIGHT, int WIN_WIDTH, Player* player, Goal* goal) {
	indicate(WIN_HEIGHT, WIN_WIDTH, player, goal);
	visible(WIN_HEIGHT, WIN_WIDTH,goal);
}
void Navi::indicate(int WIN_HEIGHT,int WIN_WIDTH,Player* player,Goal*goal) {
player2goalX = player->getPosX()-goal->getPosX() ;
player2goalY = player->getPosY() -goal->getPosY();
perY =player2goalY / (WIN_HEIGHT - player->getPosY());
perX = player2goalX / (WIN_WIDTH - player->getPosX());
	if (goal->getPosY() > player->getPosY()) {
		posX = player->getPosX() + player2goalX / perY;
	}
	else {
		posX = player->getPosX() - player2goalX / perY;
	}
	if (goal->getPosX() > player ->getPosX() ) {
		posY = player->getPosY() +player2goalY / perX;
	} else {
		posY = player->getPosY() - player2goalY / perX;

	}
	if (posY > WIN_HEIGHT-30) {
		posY = WIN_HEIGHT-30;
	}
	if (posY < 30) {
		posY = 30;
	}
	if (posX > WIN_WIDTH-30) {
		posX = WIN_WIDTH-30;
	}
	if (posX < 30) {
		posX = 30;
	}
	toGoalX = (posX - goal->getPosX());
	toGoalY = (posY - goal->getPosY());
	toGoalR = sqrt((toGoalX * toGoalX) + (toGoalY * toGoalY));
	radianX = cos(angle);
	radianY = sin(angle);
	if (toGoalX * radianX + toGoalY * radianY < 0) {
		angle = angle + (PI / 90);
	} else if (toGoalX *radianX + toGoalY * radianY < 45) {
		angle = angle;
	} else {
		angle = angle - (PI / 90);
	}
}
void  Navi::visible(int WIN_HEIGHT, int WIN_WIDTH, Goal* goal) {
	if ((goal->getPosY() < WIN_HEIGHT-goal->getRadius() && goal->getPosY() >0 + goal->getRadius())&& (goal->getPosX() < WIN_WIDTH - goal->getRadius() &&goal->getPosX() >0 + goal->getRadius())) {
		isAlive = 0;
	} else {
		isAlive = 1;
	}
}
void  Navi::draw() {
	/*DrawFormatString(0, 30, GetColor(0, 0, 0), "%lf", posX);
	DrawFormatString(0, 45, GetColor(0, 0, 0), "%lf", posY);
	DrawFormatString(0, 0, GetColor(0, 0, 0), "%lf", posX);
	DrawFormatString(0, 15, GetColor(0, 0, 0), "%lf", posY);
	DrawFormatString(0, 30, GetColor(0, 0, 0), "%d", isAlive);*/
	if (isAlive==1) {
		DrawRotaGraph((int)posX, (int)posY, 0.25f, angle, GrHandle, TRUE, TRUE);
	}
}