#pragma once
#include "Player.h"
#include "Easing.h"
#include "Enemy.h"
#include "RainbowEngine.h"

class Shake;

class Particle {
private:
	float posX;
	float posY;
	float radius;

	float speedX;
	float speedY;
	float speed;

	float angle;

	bool isActive;

public:
	Particle();

	int getIsActive();

	void setIsActive(bool isActive);

	void activate(Player *player, Enemy *enemy);
	void update(Player *player, Easing *easing);
	void draw(RainbowEngine *rainbow_engine, Shake *shake);
};