#include "Navi.h"
#include "Player.h"
#include "GameObject.h"
#include "Goal.h"
#include <DxLib.h>
#include "math.h"

Navi::Navi() {
	isAlive = 1;
	GrHandle = LoadGraph("Resources/Navi.png");
	toGoalX = 0;
	toGoalY = 0;
	toGoalR = 0;
	radianX = 0;
	radianY = 0;
	PI = 3.14f;
	angle = PI / 2;
}
void  Navi::update(int WIN_HEIGHT, int WIN_WIDTH, Player* player, Goal* goal) {
	indicate(WIN_HEIGHT, WIN_WIDTH, player, goal);
	visible(WIN_HEIGHT, WIN_WIDTH, goal);
}
void Navi::indicate(int WIN_HEIGHT, int WIN_WIDTH, Player* player, Goal* goal) {
	//position
	float player2goalX = player->getPosX() - goal->getPosX();
	float player2goalY = player->getPosY() - goal->getPosY();
	float perY = player2goalY / (WIN_HEIGHT - player->getPosY());
	float perX = player2goalX / (WIN_WIDTH - player->getPosX());

	if (goal->getPosY() > -(WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() &&
		goal->getPosY() > (WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() - WIN_HEIGHT) {
		//ã
		this->posX = player->getPosX() + player2goalX / perY;
		this->posY = 30;
	} else if (goal->getPosY() < -(WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() &&
		goal->getPosY() < (WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() - WIN_HEIGHT) {
		//‰º
		this->posX = player->getPosX() + player2goalX / perY;
		this->posY = 420;
	} else if (goal->getPosY() < -(WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() &&
		goal->getPosY() > (WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() - WIN_HEIGHT) {
		//¶
		this->posX = 30;
		this->posY = player->getPosY() + player2goalY / perX;
	} else if (goal->getPosY() > -(WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() &&
		goal->getPosY() < (WIN_HEIGHT / WIN_WIDTH) * goal->getPosX() - WIN_HEIGHT) {
		//‰E
		this->posX = 770;
		this->posY = player->getPosY() + player2goalY / perX;
	}
	// if (player2goalX < 0 && player2goalY > 0) {
	// 	// 
	// 	posX = player->getPosX() - player2goalX / perY;
	// 	posY = player->getPosY() + player2goalY / perX;
	// }else if (player2goalX < 0 && player2goalY < 0) {

	// 	posY = 420;
	// 	posX = player->getPosX() + player2goalX / perY;
	// }else if (player2goalX > 0 && player2goalY < 0) {
	// 	posX = player->getPosX() + player2goalX / perY;
	// 	posY = player->getPosY() - player2goalY / perX;
	// }else if (player2goalX > 0 && player2goalY > 0) {
	// 	if (posY == 30) {
	// 		posX = player->getPosX() - player2goalX / perY;
	// 	} else {
	// 		posX = 30;
	// 	}
	// 	posY = player->getPosY() - player2goalY / perX;
	// }

	if (posY > WIN_HEIGHT - 30) {
		posY = WIN_HEIGHT - 30;
	}

	if (posY < 30) {
		posY = 30;
	}

	if (posX > WIN_WIDTH - 30) {
		posX = WIN_WIDTH - 30;
	}
	if (posX < 30) {
		posX = 30;
	}
	// angle
	toGoalX = (posX - goal->getPosX());
	toGoalY = (posY - goal->getPosY());
	toGoalR = sqrt((toGoalX * toGoalX) + (toGoalY * toGoalY));
	radianX = cos(angle);
	radianY = sin(angle);
	if (toGoalX * radianX + toGoalY * radianY < 0) {
		angle = angle + (PI / 90);
	} else if (toGoalX * radianX + toGoalY * radianY < 45) {
		angle = angle;
	} else {
		angle = angle - (PI / 90);
	}
}
void  Navi::visible(int WIN_HEIGHT, int WIN_WIDTH, Goal* goal) {
	if ((goal->getPosX() - goal->getRadius() < WIN_WIDTH) &&
		(goal->getPosY() - goal->getRadius() < WIN_HEIGHT) &&
		(goal->getPosX() + goal->getRadius() > 0) &&
		(goal->getPosY() + goal->getRadius() > 0)
		) {
		isAlive = 0;
	} else {
		isAlive = 1;
	}
}

void  Navi::draw() {
	if (isAlive == 1) {
		DrawRotaGraph((int)posX, (int)posY, 0.25f, angle, GrHandle, TRUE, TRUE);
	}
}