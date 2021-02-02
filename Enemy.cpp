#include "DxLib.h"
#include "Enemy.h"
#include "Player.h"
#include"GameObject.h"
#include <math.h>
#include "Background.h"
#include "Shake.h"
#include"Option.h"
#include "Color.h"


Enemy::Enemy(float radius, float speed, int isAlive, int activate) {
	initX = (float)GetRand(800);
	initY = (float)GetRand(450);
	posX = (float)GetRand(800);
	posY = (float)GetRand(450);
	this->radius = radius;
	this->speed = speed;
	this->isAlive = isAlive;
	this->activate = activate;
	isFollow = 0;
	isRespawn = GetRand(4);
	count = 0;
	itX = hitPointX.begin();
	itY = hitPointY.begin();
	push = 0;
	BreakEnemy = LoadSoundMem("Resources/BreakEnemy.wav");

}

Enemy::~Enemy() {
}

float Enemy::getPosX() { return posX; }
float Enemy::getPosY() { return posY; }
float Enemy::getRadius() { return radius; }
float Enemy::getSpeed() { return speed; }
int Enemy::getIsAlive() { return isAlive; }
int Enemy::getActivate() { return activate; }

int Enemy::getHitPointSize() { return hitPoint.size(); }
float Enemy::getHitPointX() { return hpXBuf; }
float Enemy::getHitPointY() { return hpYBuf; }


void Enemy::setPosX(float posX) { this->posX = posX; }
void Enemy::setPosY(float posY) { this->posY = posY; }
void Enemy::setRadius(float radius) { this->radius = radius; }
void Enemy::setSpeed(float speed) { this->speed = speed; }
void Enemy::setIsAlive(int isAlive) { this->isAlive = isAlive; }
void Enemy::setActivate(int  activate){ this->activate = activate; }

//void Enemy::setHitPoint() { hitPoint; }
void Enemy::setHitPointX(float hitPointX) { this->hpXBuf = hitPointX; }
void Enemy::setHitPointY(float hitPointY) { this->hpYBuf = hitPointY; }

void Enemy::addHitPoint(int index) {
	hitPoint.push_back(1);
	hitPointX.push_back(posX);
	hitPointY.push_back(posY);
	/*hitPoint++;
	hitPointX[index] = posX;
	hitPointY[index] = posY;*/
}

void Enemy::subHitPoint(int index) {
	hitPoint.pop_back();
	hitPointX.pop_back();
	hitPointY.pop_back();
	/*hitPoint--;
	hitPointX[index] = 0;
	hitPointY[index] = 0;*/
}

void Enemy::arrayToObject(int index) {
	/**itX + index;
	*itY + index;

	hpXBuf = *itX;
	hpYBuf = *itY;

	itX = hitPointX.begin();
	itY = hitPointY.begin();*/

	hpXBuf = hitPointX[index];
	hpYBuf = hitPointY[index];
}

void Enemy::ObjectToArray(int index) {
	/*itX + index;
	itY + index;

	*itX = hpXBuf;
	*itX = hpYBuf;

	itX = hitPointX.begin();
	itY = hitPointY.begin();*/

	hitPointX[index] = hpXBuf;
	hitPointY[index] = hpYBuf;
}

void Enemy::update(Enemy* enemy, Player* player, Shake* shake, Background* Background, char keys[255], char oldkeys[255], Option* option) {
	move(player, Background);
	collide(enemy, player, shake, keys, oldkeys, option);
	respawn(Background);
}
void Enemy::collide(Enemy* enemy, Player* player, Shake* shake, char keys[255], char oldkeys[255], Option* option) {
	float a = posX - player->getAttackX();
	float b = posY - player->getAttackY();
	float distance = sqrtf(a * a + b * b);
	float Radius = radius + player->getAttackR();
	float c = posX - player->getPosX();
	float d = posY - player->getPosY();
	float dis = sqrtf(c * c + d * d);
	float Rad = radius + player->getRadius();
	if (activate == 1) {
		if (player->getIsAlive() == 1) {
			if (keys[KEY_INPUT_SPACE] == 0 && oldkeys[KEY_INPUT_SPACE] == 1) {
				if (player->getAttackR() < 40) {
					shake->setIntensify(10);
				} else if (player->getAttackR() < 70) {
					shake->setIntensify(20);
				} else {
					shake->setIntensify(30);
				}
				if (distance < player->getAttackR() - radius) {
					if (distance <= Radius && isAlive == 1) {
						//“GŽ€‚Ê
						if (CheckSoundMem(BreakEnemy) == 0) {

							ChangeVolumeSoundMem(255 * option->getVolume() / 100, BreakEnemy);
							PlaySoundMem(BreakEnemy, DX_PLAYTYPE_BACK);
						}
						isAlive = 0;
						/*for (int i = 0; i < 50; i++) {
							if (hitPointX[i] != 0) {
								enemy->addHitPoint(i);
								break;
							}
						}*/
						if (hitPoint.size() <= 5) {
							enemy->addHitPoint(0);
						}

					}
				}
			}
		}
	}
	if (isAlive == 1) {
		if (dis <= Rad) {
				isAlive = 0;
		}
	}
}
void Enemy::move(Player* player, Background* background) {
	if (isAlive == 1) {
		float toPlayerX = (player->getPosX() - background->getScrollX() - (posX - background->getScrollX()));
		float toPlayerY = (player->getPosY() - background->getScrollY() - (posY - background->getScrollY()));
		float toPlayerR = (float)sqrt(pow(toPlayerX, 2) + pow(toPlayerY, 2));
		if (background->getMoveFlag() == 0) {
			posX += (toPlayerX / toPlayerR * speed);
			posY += (toPlayerY / toPlayerR * speed);
		} else if (background->getMoveFlag()==1){
			posX += (toPlayerX / toPlayerR * speed);
			posY = posY ;
		} else if (background->getMoveFlag() == 2) {
			posX += (toPlayerX / toPlayerR * speed);
			posY = posY;
		} else if (background->getMoveFlag() == 3) {
			posX =posX;
			posY += (toPlayerY / toPlayerR * speed);
		} else {
			posX = posX;
			posY += (toPlayerY / toPlayerR * speed);
		}
	}
}
void Enemy::draw(Shake* shake, Color* color) {
	if (isAlive == 1) {
		DrawBoxAA(
			posX - radius + shake->getShakeX(),
			posY - radius + shake->getShakeY(),
			posX + radius + shake->getShakeX(),
			posY + radius + shake->getShakeY(),
			color->getRED2(),
			TRUE);
	}
}

void Enemy::respawn(Background* Background) {
	if (activate==1) {
		if (isAlive == 0) {
			count++;
			if (count == 30) {
				if (isRespawn == 0) {
					posX = -Background->getScrollX() + 830;
					posY = -Background->getScrollY() + 480;
				} else if (isRespawn == 1) {
					posX = -Background->getScrollX() + 1570;
					posY = -Background->getScrollY() + 480;
				} else if (isRespawn == 2) {
					posX = -Background->getScrollX() + 830;
					posY = -Background->getScrollY() + 870;
				} else {
					posX = -Background->getScrollX() + 1570;
					posY = -Background->getScrollY() + 870;
				}
				isAlive = 1;
				count = 0;
			}
		}
	}
}

