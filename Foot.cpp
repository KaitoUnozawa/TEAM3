#include "Foot.h"
#include "BackGraoud.h"
#include"GameObject.h"
#include <DxLib.h>

int Foot::getIsVisible() { return isVisible; }
Foot::Foot() {
	posX = 0;
	posY = 0;
	radius = 8;
	bright = 255;
	isVisible = 0;
}
void Foot::prepare(BackGraoud* backgraoud) {
	posX = backgraoud->getWorldX()- backgraoud->getScrollX();
	posY = backgraoud->getWorldY() - backgraoud->getScrollY();
	isVisible = 1;
}
void Foot::visible() {
	if (isVisible == 1) {
		bright -= 5;
		if (bright == 0) {
			bright = 255;
			isVisible = 0;
		}
	}
}
void Foot::draw() {
	if (isVisible == 1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, bright);
		DrawCircleAA(posX, posY, radius, 64, GetColor(0xc8, 0xc8, 0xc8), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}