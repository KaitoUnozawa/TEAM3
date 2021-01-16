#include "Player.h"
#include <DxLib.h>
#include"GameObject.h"



Player::Player(float posX, float posY, float radius, float speed) {
	this->posX = posX;
	this->posY = posY;
	this->radius = radius;
	this->speed = speed;
	attackX = 0, attackY = 0, readyR = 0, attackR = 0;
	isAlive = 0;
	isAttack = 0;
}

Player::~Player() {
}

float Player::getPosX() { return posX; }
float Player::getPosY() { return posY; }
float Player::getRadius() { return radius; }
float Player::getSpeed() { return speed; }
float Player::getAttackX() {return  attackX;}
float Player::getAttackY() {return attackY;}
float Player::getAttackR() {return attackR;}
int Player::getIsAttack() {return isAttack;}
void Player::setPosX(float posX) { this->posX = posX; }
void Player::setPosY(float posY) { this->posY = posY; }
void Player::setRadius(float radius) { this->radius = radius; }
void Player::setSpeed(float speed) { this->speed = speed; }
void Player::setIsAttack(int isAttack) { this->isAttack = isAttack; }


void Player::update(char keys[255], char oldkeys[255], int WIN_WIDTH) {
	move(keys, oldkeys, WIN_WIDTH);
	create();
	enclose();
}
void Player::enclose() {
	if (isAlive == 1) {
		if (attackR > 0) {
			attackR--;
		}else{
			attackX = -50;
			attackY = posY;
			isAlive = 0;
		}
	}
}
void  Player::create() {
	if (isAttack == 1) {
		attackX = posX;
		attackY = posY;
		attackR = readyR;
		readyR = radius - 1;
		isAlive = 1;
		isAttack = 0;
	}
}
void Player::move(char keys[255], char oldkeys[255], int WIN_WIDTH) {
	if (posX < 8) {
		posX = 8;
	}
	if (posX > 792) {
		posX = 792;
	}
	if (posY < 8) {
		posY = 8;
	}
	if (posY > 442) {
		posY = 442;
	}
	if (keys[KEY_INPUT_RIGHT] == 1) {
		posX += speed;
	}
	if (keys[KEY_INPUT_LEFT] == 1) {
		posX -= speed;
	}
	if (keys[KEY_INPUT_UP] == 1) {
		posY -= speed;
	}
	if (keys[KEY_INPUT_DOWN] == 1) {
		posY += speed;
	}
	if (isAlive == 0) {
		if (keys[KEY_INPUT_SPACE] == 1) {
			readyR++;
		}
		if (keys[KEY_INPUT_SPACE] == 0 && oldkeys[KEY_INPUT_SPACE] == 1) {
			isAttack = 1;
		}
	}
}
void Player::draw() {
	//DrawFormatString(0,0,GetColor(0,0,0),"%lf", attackX);
	if (isAlive == 0) {
		DrawCircleAA(posX, posY, readyR, 64, GetColor(230, 138, 230), 0, 1);
	}if (isAlive == 1) {
		DrawCircleAA(attackX, attackY, attackR, 64, GetColor(230, 92, 230), 1, 1);
	}
	DrawBoxAA(
		posX - radius,
		posY - radius,
		posX + radius,
		posY + radius,
		GetColor(92, 92, 230),
		TRUE);
}
