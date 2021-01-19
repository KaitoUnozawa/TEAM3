#include "Goal.h"
#include <DxLib.h>
#include"GameObject.h"
float Goal::getPosX() { return posX; }
float Goal::getPosY() { return posY; }
float Goal::getRadius() { return radius; }
void Goal::setPosX(float posX) { this->posX = posX; }
void Goal::setPosY(float posY) { this->posY = posY; }
void Goal::setRadius(float radius) { this->radius = radius; }
Goal:: Goal() {
	posX = 300;
	posY =600;
	radius = 16;
	isAlive = 0;
	image = LoadGraph("Resources/Enemy.png");
}
void Goal::update(int WIN_WIDTH, int WIN_HEIGHT, char keys[256]) {
	create(WIN_WIDTH, WIN_HEIGHT,keys);
}
void  Goal::create(int WIN_WIDTH, int WIN_HEIGHT,char keys[256]) {
	//if (isAlive == 0) {
		//posX = GetRand(WIN_WIDTH)+WIN_WIDTH;
		//posY = GetRand(WIN_HEIGHT) + WIN_HEIGHT;
		//isAlive = 1;
	//}
	if (keys[KEY_INPUT_W] == 1) {
		posY -= 5;
	}
	if (keys[KEY_INPUT_A] == 1) {
		posX -= 5;
	}
	if (keys[KEY_INPUT_S] == 1) {
		posY += 5;
	}
	if (keys[KEY_INPUT_D] == 1) {
		posX += 5;
	}
}

void Goal::draw() {
	/*DrawFormatString(0, 0, GetColor(0, 0, 0), "%lf", posX);
	DrawFormatString(0, 15, GetColor(0, 0, 0), "%lf", posY);*/
	//SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
	DrawCircleAA(
		posX,
		posY,
		radius,
		128,
		GetColor(230, 230, 92),
		TRUE);

	//DrawCircleGauge(200, 200, 100, image, 0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

}
