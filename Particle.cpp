#include "Particle.h"
#include "DxLib.h"
#include "Player.h"
#include "Particle.h"
#include "DxLib.h"
#include "Player.h"
#include <cmath>
#include "Enemy.h"
#include "RainbowEngine.h"
#include "Shake.h"
#include "Color.h"

Particle::Particle() {
	posX = -100.0f;
	posY = -100.0f;
	radius = 30.0f;
	speedX = 0.0f;
	speedY = 0.0f;
	speed = 5.0f;
	angle = 0;
	isActive = false;
}

int Particle::getIsActive() { return isActive; }

void Particle::setIsActive(bool isActive) { this->isActive = isActive; }

void Particle::activate(Player* player, Enemy* enemy) {
	if (enemy->getActivate() == 1) {
		if (enemy->getIsAlive() == 0 && isActive == false) {
			posX = enemy->getPosX() + enemy->getRadius();
			posY = enemy->getPosY() + enemy->getRadius();

			angle = GetRand(360);

			speedX = speed * cos(angle);
			speedY = speed * sin(angle);

			radius = GetRand(enemy->getRadius() * 10) + 30;

			isActive = true;
		}

	}

	/*if (player->getIsAlive() == 0) {
		posX = player->getPosX() + player->getRadius();
		posY = player->getPosY() + player->getRadius();

		angle = GetRand(360);

		speedX = speed * cos(angle);
		speedY = speed * sin(angle);

		radius = GetRand(player->getRadius()) + player->getRadius() / 2;

		isActive = true;
	}*/
}

void Particle::update(Player* player, Easing* easing) {
	static int frame = 0;

	if (isActive == true) {
		frame++;
		posX += speedX;
		posY += speedY;

		radius *= 0.9f;

		if (radius <= 0.1f) {
			isActive = false;
		}
	}
}

void Particle::draw(Color* color, Shake* shake) {
	if (radius >= 0.0f) {
		SetDrawBlendMode(DX_BLENDMODE_ADD, 40);

		DrawBox(
			posX - radius + shake->getShakeX(),
			posY - radius + shake->getShakeY(),
			posX + radius + shake->getShakeX(),
			posY + radius + shake->getShakeY(),
			color->rainbowEngine(10),
			TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 40);
	}
	SetFontSize(20);
	DrawFormatString(0, 15, GetColor(0, 0, 0), "%lf", radius);
	DrawFormatString(0, 30, GetColor(0, 0, 0), "%d", isActive);
}