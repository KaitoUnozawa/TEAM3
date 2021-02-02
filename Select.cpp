#include <cmath>
#include "Select.h"
#include "DxLib.h"
#include "Easing.h"
#include "SceneTransition.h"
#include "Color.h"

Select::Select() {
	posX = WIN_WIDTH / 2;
	posY = WIN_HEIGHT / 2;
	speedX = 0;
	speedY = 0;
	radius = 0;
	angle = 0;

	speed = 10;

	index = 0;
	//count = 0;
	frame = 0;
}

void Select::update(SceneTransition* scene_transition, Easing* easing, Color* color, int index) {
	if (scene_transition->getIsOver() == 1) {
		makeAngle(color,index);
		moveCircle(easing);
	}
}

void Select::makeAngle(Color* color,int index) {
	speedX = sin(index * 36 * DX_PI / 180) * speed;
	speedY = cos(index * 36 * DX_PI / 180) * speed;

	this->index = index;
	if (index == 0) {
		this->color = color->getRED();
	} else if (index == 1) {
		this->color = color->getORANGE();
	} else if (index == 2) {
		this->color = color->getYELLOW();
	} else if (index == 3) {
		this->color = color->getGREEN();
	} else if (index == 4) {
		this->color = color->getGREEN2();
	} else if (index == 5) {
		this->color = color->getGREEN3();
	} else if (index == 6) {
		this->color = color->getBLUE();
	} else if (index == 7) {
		this->color = color->getBLUE3();
	} else if (index == 8) {
		this->color = color->getPURPLE();
	} else if (index == 9) {
		this->color = color->getPURPLE2();
	}
}

void Select::moveCircle(Easing* easing) {
	static int count = 0;
	count++;
	static int frame = 0;
	frame++;

	for (int i = 0; i < 10; i++) {
		if (index == i && count > 4 * i) {
			if (radius < 30) {
				speedX* easing->easeOutBack(frame, 50);
				speedY* easing->easeOutBack(frame, 50);

				posX += speedX;
				posY -= speedY;

				/*posX = priPosX + 30 * easing->easeOutBack(frame, 50);
				posY = priPosY + 30 * easing->easeOutBack(frame, 50);*/

				radius += 2;
			}
		}
	}
}

void Select::draw() {
	/*DrawLine(0, WIN_HEIGHT / 2, WIN_WIDTH, WIN_HEIGHT / 2, BLACK);
	DrawLine(WIN_WIDTH / 2, 0, WIN_WIDTH / 2, WIN_HEIGHT, BLACK);*/

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawCircle(posX, posY, radius, GetColor(200, 0, 0), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 100);
}