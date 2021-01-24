#include "Player.h"
#include <DxLib.h>
#include "GameObject.h"
#include "Enemy.h"
#include <cstdlib>

Player::Player(float posX, float posY, float radius, float speed) {
	this->posX = posX;
	this->posY = posY;
	this->radius = radius;
	this->speed = speed;
	attackX = 0, attackY = 0, readyR = 0, attackR = 0;
	isAlive = 0;
	isAttack = 0;
	isMove = 0;
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
int Player::getIsMove() { return isMove; }

void Player::setPosX(float posX) { this->posX = posX; }
void Player::setPosY(float posY) { this->posY = posY; }
void Player::setRadius(float radius) { this->radius = radius; }
void Player::setSpeed(float speed) { this->speed = speed; }
void Player::setIsAttack(int isAttack) { this->isAttack = isAttack; }


void Player::update(BackGraoud* backgraoud, char keys[255], char oldkeys[255], int WIN_WIDTH) {
	move(keys, oldkeys, WIN_WIDTH);
	create();
	enclose();
	hitPointMove(backgraoud);
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
		//posX += speed;
		isMove = 1;
	}
	if (keys[KEY_INPUT_LEFT] == 1) {
		//posX -= speed;
		isMove = 1;
	}
	if (keys[KEY_INPUT_UP] == 1) {
		//posY -= speed;
		isMove = 1;
	}
	if (keys[KEY_INPUT_DOWN] == 1) {
		//posY += speed;
		isMove = 1;
	}
	if (keys[KEY_INPUT_RIGHT] == 0 &&
		keys[KEY_INPUT_LEFT] == 0 &&
		keys[KEY_INPUT_UP] == 0 &&
		keys[KEY_INPUT_DOWN] == 0) {
		isMove = 0;
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
void Player::hitPointMove(BackGraoud* backgraoud) {
	int size = hitPoint.size();
	float aX2bX;
	float aY2bY;

	for (int i = 0; i < size; i++) {
		// 1つ手前のオブジェクトを追従するようにしています
		if (i == 0) {
			aX2bX = hitPointX[i] - posX;
			aY2bY = hitPointY[i] - posY;
		} else {
			aX2bX = hitPointX[i] - hitPointX[i - 1];
			aY2bY = hitPointY[i] - hitPointY[i - 1];
		}

		float aR2bR = (float)sqrt(abs(aX2bX * aX2bX) + abs(aY2bY * aY2bY));

		// 敵の時は+でいけたのに何故か-じゃないと上手くいきません。なんで？？？
		if (backgraoud->getMoveFlag() == 0 && aR2bR > i + 1 * 30) {
			hitPointX[i] -= aX2bX / aR2bR * speed;
			hitPointY[i] -= aY2bY / aR2bR * speed;
		}
		if (backgraoud->getMoveFlag() == 1 && aR2bR > i + 1 * 30) {
			hitPointX[i] -= aX2bX / aR2bR * speed;
		}
		if (backgraoud->getMoveFlag() == -1 && aR2bR > i + 1 * 30) {
			hitPointY[i] -= aY2bY / aR2bR * speed;
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

	// HP
	int size = hitPoint.size();

	for (int i = 0; i < size; i++) {
		DrawBoxAA(
			hitPointX[i] - radius,
			hitPointY[i] - radius,
			hitPointX[i] + radius,
			hitPointY[i] + radius,
			GetColor(92, 92, 230),
			TRUE);
	}
}
