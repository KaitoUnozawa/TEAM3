#include <cstdlib>
#include "DxLib.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Shake.h"
#include "Option.h"
#include "Color.h"

Player::Player(float radius, float speed) {
	this->posX = 0;
	this->posY = 0;
	this->radius = radius;
	this->speed = speed;
	effectX = 0;
	effectY = 0;
	effectR = 0;
	frameMax = 0;
	pal = 0; priPos=0;
	attackX = 0, attackY = 0, readyR = 0, attackR = 0;
	isAlive = 0;
	isAttack = 0;
	hp = 1;
	hpSize = 0;
	ExtendBgm = LoadSoundMem("Resources/extend.wav");
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
int Player::getIsAlive() { return isAlive; }
int Player::getHp() { return hp; }
void Player::setPosX(float posX) { this->posX = posX; }
void Player::setPosY(float posY) { this->posY = posY; }
void Player::setRadius(float radius) { this->radius = radius; }
void Player::setSpeed(float speed) { this->speed = speed; }
void Player::setIsAttack(int isAttack) { this->isAttack = isAttack; }


void Player::update(Enemy* enemy, Background* background, Easing* easing, char keys[255], char oldkeys[255], int WIN_WIDTH, Option* option) {
	move(keys, oldkeys, WIN_WIDTH,option);
	create();
	enclose(easing);
	hitPointMove(enemy, background);
	for (int i = 0; i < 10; i++) {
	collide(enemy+i);
	}
}
void Player::enclose(Easing* easing) {
	static int frame = 0;

	if (isAlive == 1) {
		if (attackR > 0) {
			frame++;
			attackR -= easing->easeInBack(frame, frameMax);
			effectR = priPos + 200 * easing->easeOutQuint(frame, 50);
			pal -= 15;
		} else {
			attackX = -50;
			attackY = posY;
			isAlive = 0;
			frame = 0;
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
		frameMax = (int)attackR;
		effectX = posX;
		effectY = posY;
		effectR = attackR;
		priPos = attackR;
		pal = 255;
		isAttack = 0;

	}
}
void  Player::move(char keys[255], char oldkeys[255], int WIN_WIDTH, Option* option){
if (isAlive == 0) {
		if (keys[KEY_INPUT_SPACE] == 1) {
			readyR++;
		}
		if (keys[KEY_INPUT_SPACE] == 0 && oldkeys[KEY_INPUT_SPACE] == 1) {
			if (isAttack != 1) {
				isAttack = 1;
			}
		}
	}
}
void Player::hitPointMove(Enemy* enemy, Background* background) {
	int size = enemy->getHitPointSize();
	float aX2bX;
	float aY2bY;
	float hitPointX;
	float hitPointY;
	float previousHitPointX;
	float previousHitPointY;

	for (int i = 0; i < size; i++) {
		enemy->arrayToObject(i);

		hitPointX = enemy->getHitPointX();
		hitPointY = enemy->getHitPointY();

		if (i == 0) {
			aX2bX = hitPointX - posX;
			aY2bY = hitPointY - posY;
		} else {
			aX2bX = hitPointX - previousHitPointX;
			aY2bY = hitPointY - previousHitPointY;
		}

		float aR2bR = (float)sqrt(abs(pow(aX2bX,2)) + abs(pow(aY2bY,2)));

		if (background->getMoveFlag() == 0 && aR2bR > i + 1 * 30) {
			hitPointX -= aX2bX / aR2bR * speed;
			hitPointY -= aY2bY / aR2bR * speed;
		}
		if (background->getMoveFlag() == 1 && aR2bR > i + 1 * 30) {
			hitPointX -= aX2bX / aR2bR * speed;
		}
		if (background->getMoveFlag() == -1 && aR2bR > i + 1 * 30) {
			hitPointY -= aY2bY / aR2bR * speed;
		}

		enemy->setHitPointX(hitPointX);
		enemy->setHitPointY(hitPointY);
		enemy->ObjectToArray(i);

		previousHitPointX = hitPointX;
		previousHitPointY = hitPointY;
	}
}
void Player::collide(Enemy* enemy) {
	float a = posX - enemy->getPosX();
	float b = posY - enemy->getPosY();
	float distance = sqrtf(a * a + b * b);
	float Radius = radius + enemy->getRadius();
	if(enemy->getIsAlive()==1){
		if (distance <= Radius) {
			if (enemy->getHitPointSize() == 0) {
				hp = 0;
			} else {
				enemy->subHitPoint(0);
			}
		}
	}
}
void Player::draw(Enemy* enemy, Shake* shake, Color* color) {


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	if (isAlive == 0 || isAlive == 1) {
		DrawCircleAA(
			posX + shake->getShakeX(),
			posY + shake->getShakeY(),
			readyR,
			64,
			GetColor(100, 100, 100), 0, 1);
	}
	if (isAlive == 1) {
		DrawCircleAA(
			attackX + shake->getShakeX(),
			attackY + shake->getShakeY(),
			attackR,
			64,
			GetColor(100, 100, 100), 1, 1);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);

	DrawBoxAA(
		posX - radius + shake->getShakeX(),
		posY - radius + shake->getShakeY(),
		posX + radius + shake->getShakeX(),
		posY + radius + shake->getShakeY(),
		color->getBLUE(),
		TRUE);

	// HP
	int size = enemy->getHitPointSize();
	float hitPointX;
	float hitPointY;

	for (int i = 0; i < size; i++) {
		enemy->arrayToObject(i);
		hitPointX = enemy->getHitPointX();
		hitPointY = enemy->getHitPointY();

		DrawBoxAA(
			hitPointX - radius + shake->getShakeX(),
			hitPointY - radius + shake->getShakeY(),
			hitPointX + radius + shake->getShakeX(),
			hitPointY + radius + shake->getShakeY(),
			GetColor(92, 92, 230),
			TRUE);
	}
}
void Player::drawEffect() {
	if (isAlive == 1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
		DrawCircle(
			(int)effectX,
			(int)effectY,
			(int)effectR,
			GetColor(100, 100, 100), 0, 1);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, pal);
	}
}
