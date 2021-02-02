#include "math.h"
#include <DxLib.h>
#include "Goal.h"
#include "GameObject.h"
#include "Shake.h"
#include "Player.h"
#include "Enemy.h"
#include "Color.h"
float Goal::getPosX() { return posX; }
float Goal::getPosY() { return posY; }
float Goal::getRadius() { return radius; }
float Goal::getInitX() { return initX; }
float Goal::getInitY() { return initY; }
int Goal::getIsClear() { return isClear; }
void Goal::setIsClear(int isClear) { this->isClear = isClear; }
void Goal::setPosX(float posX) { this->posX = posX; }
void Goal::setPosY(float posY) { this->posY = posY; }
void Goal::setRadius(float radius) { this->radius = radius; }
Goal::Goal() {
	initX = (float)GetRand(2384);
	initY = (float)GetRand(1334);
	posX = 0;
	posY = 0;
	radius = 16;
	isAlive = 0;
	isClear = 0;
	R = 255;
	G = 0;
	B = 0;
	image = LoadGraph("Resources/Enemy.png");
	gauge = 100;
	efRadius = 0;
	priPos = 0;
	pal = 0;

}
void Goal::update(int WIN_WIDTH, int WIN_HEIGHT, Background* backgraund, Player* player, Enemy* enemy) {
	create(WIN_WIDTH, WIN_HEIGHT, backgraund);
	collide(player, enemy);
}
void Goal::create(int WIN_WIDTH, int WIN_HEIGHT, Background* backgraund) {
	posX = initX - backgraund->getScrollX();
	posY = initY - backgraund->getScrollY();
}
void Goal::collide(Player* player, Enemy* enemy) {
	float a = posX - player->getPosX();
	float b = posY - player->getPosY();
	float distance = sqrtf(a * a + b * b);
	float Radius = radius + player->getRadius();
	if (distance <= Radius && enemy->getHitPointSize() != 0) {
		gauge--;
	} else {
		if (gauge < 100) {
			gauge++;
		}
	}

	if (gauge != 0) {
		isCollect = 0;
	}

	if (gauge <= 0) {
		//isClear = 1;
		isCollect = 1;
		enemy->subHitPoint(0);
		gauge = 100;
	}
}
void Goal::draw(Shake* shake, Color* color) {
	DrawCircleGauge(posX + shake->getShakeX(), posY + shake->getShakeY(), 100, image, 0);
	SetDrawBright(R, G, B);
	DrawCircleGauge(posX + shake->getShakeX(), posY + shake->getShakeY(), gauge, image, 0);
	SetDrawBright(255, 255, 255);

	if (pal > 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
		DrawCircle(posX, posY, efRadius, color->getYELLOW(), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, pal);
	}
}
