#include <DxLib.h>
#include "Enemy.h"
#include "Player.h"
#include"GameObject.h"
#include "math.h"
#include "BackGraoud.h"



Enemy::Enemy(float radius, float speed,int isAlive) {
	initX = (float)GetRand(800);
	initY = (float)GetRand(450);
	posX = (float)GetRand(800);
	posY = (float)GetRand(450);
	this->radius = radius;
	this->speed = speed;
	this->isAlive = isAlive;
	isFollow = 0;
}

Enemy::~Enemy() {
}

float Enemy::getPosX() { return posX; }
float Enemy::getPosY() { return posY; }
float Enemy::getRadius() { return radius; }
float Enemy::getSpeed() { return speed; }
int Enemy::getIsAlive() { return isAlive; }

void Enemy::setPosX(float posX) { this->posX = posX; }
void Enemy::setPosY(float posY) { this->posY = posY; }
void Enemy::setRadius(float radius) { this->radius = radius; }
void Enemy::setSpeed(float speed) { this->speed = speed; }
void Enemy::setIsAlive(int isAlive) { this->isAlive = isAlive; }

void Enemy::update(Player* player, BackGraoud* backgraoud, char keys[255], char oldkeys[255]) {
	move(player, backgraoud);
	collide(player,keys,oldkeys);
}
void Enemy::collide(Player* player, char keys[255], char oldkeys[255]) {
		float a = posX - player->getAttackX();
		float b = posY - player->getAttackY();
		float distance = sqrtf(a * a + b * b);
		float Radius = radius + player->getAttackR();
		if (keys[KEY_INPUT_SPACE] == 0 && oldkeys[KEY_INPUT_SPACE] == 1) {
			if (distance < player->getAttackR() - radius) {
				if (distance <= Radius) {
					isAlive = 0;
					player->hitPoint.push_back(1);
					player->hitPointX.push_back(posX);
					player->hitPointY.push_back(posY);

				}
			}
		}
	
}
void Enemy::move(Player *player,BackGraoud *backgraoud) {
		if (isAlive == 1) {
			float aX2bX = (player->getPosX() - posX);
			float aY2bY = (player->getPosY() - posY);
			float aR2bR = (float)sqrt((aX2bX * aX2bX) + (aY2bY * aY2bY));
			posX += (aX2bX / aR2bR * speed);
			posY += (aY2bY / aR2bR * speed);
			/*radianX = cos(angle);
			radianY = sin(angle);
			if (aX2bX * radianX + aY2bY * radianY < 0) {
				angle = angle + (PI / 90);
			} else if (aX2bX * radianX + aY2bY * radianY < 45) {
				angle = angle;
			} else {
				angle = angle - (PI / 90);
			}*/
	}
}
void Enemy::draw(BackGraoud* backgraoud) {
	if (isAlive == 1) {
		DrawBoxAA(
		(posX-radius),
		(posY-radius),
		(posX + radius),
		(posY + radius),
		GetColor(230, 92, 92),
		TRUE);
	}
}
