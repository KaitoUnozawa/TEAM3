#include "DxLib.h"
#include "SceneTransition.h"
#include "Color.h"
#include "Easing.h"
#include "Player.h"

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 450;

SceneTransition::SceneTransition() {
	posX = 0;
	posY = 0;
	radius = 0;
	priPos = 0;
	isOver = false;
}

int SceneTransition::getIsIncreaseOver() { return isIncreaseOver; }
int SceneTransition::getIsOver() { return isOver; }

void SceneTransition::update(Player* player, Easing* easing) {
	increase(player, easing);
	decrease(player, easing);
}

void SceneTransition::increase(Player* player, Easing* easing) {
	static int frame = 0;
	isOver = false;

	posX = player->getPosX();
	posY = player->getPosY();

	if (radius < 800) {
		frame++;
		radius = priPos + 800 * easing->easeInExpo(frame, 50);
	} else if (radius >= 800) {
		frame = 0;
		priPos = radius;
		isIncreaseOver = true;
	}
}

void SceneTransition::decrease(Player* player, Easing* easing) {
	static int frame = 0;

	if (isIncreaseOver == true && radius >= 0) {
		posX = WIN_WIDTH / 2;
		posY = WIN_HEIGHT / 2;

		frame++;
		radius = priPos - 800 * easing->easeOutExpo(frame, 50);
	}

	if (radius <= 0) {
		isOver = true;
	}
}

void SceneTransition::draw(Color* color) {
	if (radius > 1) {
		DrawCircle(posX, posY, radius, color->getORANGE(), TRUE);
	}
}