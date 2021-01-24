#include "Goal.h"
#include <DxLib.h>
#include "math.h"
#include"GameObject.h"
float Goal::getPosX() { return posX; }
float Goal::getPosY() { return posY; }
float Goal::getRadius() { return radius; }
void Goal::setPosX(float posX) { this->posX = posX; }
void Goal::setPosY(float posY) { this->posY = posY; }
void Goal::setRadius(float radius) { this->radius = radius; }
Goal:: Goal() {
	posX = 1800;
	posY =600;
	radius = 16;
	isAlive = 0;
	R = 255;
	G = 0;
	B = 0;
	image = LoadGraph("Resources/Enemy.png");
	gauge = 100;
}
void Goal::update(int WIN_WIDTH, int WIN_HEIGHT, BackGraoud* backgraund, Player* player){
	create(WIN_WIDTH, WIN_HEIGHT, backgraund);
	collide(player);
}
void  Goal::create(int WIN_WIDTH, int WIN_HEIGHT, BackGraoud* backgraund) {
	/*if (gauge > 70) {
		R = 255;
		G = 0;
		B = 0;
	} else if (gauge>30) {
		R = 0;
		G = 255;
		B = 0;
	} else if (gauge > 0) {
		R = 0;
		G = 0;
		B = 255;
	}*/
		posX = 1500 - backgraund->getScrollX();
		posY = 500 - backgraund->getScrollY();
}
void Goal::collide(Player* player) {
	float a = posX - player->getPosX();
	float b = posY - player->getPosY();
	float distance = sqrtf(a * a + b * b);
	float Radius = radius + player->getRadius();
	if (distance <= Radius) {
		gauge--;
	} else {
		if(gauge < 100){
			gauge++;
		}
	}
}
void Goal::draw() {
	DrawCircleGauge(posX, posY, 100, image, 0);
	SetDrawBright(R, G, B);
	DrawCircleGauge(posX,posY, gauge, image, 0);
	SetDrawBright(255, 255, 255);
}
