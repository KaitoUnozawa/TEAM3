#include "DxLib.h"
#include "BackGround.h"
#include "Player.h"
#include "Shake.h"
#include "math.h"

int Background::getMoveFlag() { return moveFlag; }
float Background::getWorldX() { return worldX; }
float Background::getWorldY() { return worldY; }
float Background::getScrollX() { return scrollX; }
float Background::getScrollY() { return scrollY; }

Background::Background() {
	worldX = 1200, worldY = 675;
	scrollX = 800, scrollY = 450;
	startX = 600, startY = 400;
	moveFlag = 0;
	InputX = 0;
	InputY = 0;
	PadInput = 0;
	count = 0;
	alpha = 100;
	angle = 0;
}
void Background::update(char keys[255], char oldkeys[255], Player* player, Easing* easing) {
	Background::move(keys, oldkeys, player, easing);
}
void Background::move(char keys[255], char oldkeys[255], Player* player, Easing* easing) {
	player->setPosX(worldX - scrollX);
	player->setPosY(worldY - scrollY);
	if (keys[KEY_INPUT_UP] == 1) {
		if (worldY > 39) {
			if (worldY - scrollY < startY - 350 && scrollY > 0) {
				moveFlag = 1;
				scrollY -= 4;
			} else {
				moveFlag = 0;
			}
			worldY -= 4;
		}
	} 
	if (keys[KEY_INPUT_DOWN] == 1) {
		if (worldY < 1304) {
			if (worldY - scrollY > startY && scrollY < 900) {
				moveFlag = 2;
				scrollY += 4;
			} else {
				moveFlag = 0;
			}
			worldY += 4;
		}
	} 
	if (keys[KEY_INPUT_RIGHT] == 1) {
		if (worldX < 2360) {
			if (worldX - scrollX > startX && scrollX < 1600) {
				moveFlag = 3;
				scrollX += 4;
			} else {
				moveFlag = 0;
			}
			worldX += 4;
		}
	}
	if (keys[KEY_INPUT_LEFT] == 1 ) {
		if (worldX > 40) {
			if (worldX - scrollX < startX - 500 && scrollX > 0) {
				moveFlag = 4;
				scrollX -= 4;
			} else {
				moveFlag = 0;
			}
			worldX -= 4;
		}
	}
}

void Background::draw(Shake* shake, Color* color) {

	alpha = (int)(sin(count / 30.0) * 30 + 100.0);
	count++;
	if (count > 180) {
		count = 0;
	}
	const int BLACK = GetColor(50, 50, 50);
	const int BACK_LENGTH = 32;
	// îwåi
	SetDrawBlendMode(DX_BLENDMODE_ADD, 50);
	// èc
	for (int i = 0; i < 75; i++) {
		DrawLine(
			-scrollX + (i * 32) + shake->getShakeX(),
			0 + shake->getShakeY(),
			-scrollX + (i * 32) + shake->getShakeX(),
			1350 + shake->getShakeY(),
			BLACK);
	}
	// â°
	for (int i = 0; i < 43; i++) {
		DrawLine(
			0 + shake->getShakeX(),
			-scrollY + (i * 32) + shake->getShakeY(),
			2400 + shake->getShakeX(),
			-scrollY + (i * 32) + shake->getShakeY(),
			BLACK);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawCircleAA(-scrollX + 830 + shake->getShakeX(), -scrollY + 480 + shake->getShakeY(), 20, 15, GetColor(0, 0, 255), TRUE, TRUE);
	DrawCircleAA(-scrollX + 1570 + shake->getShakeX(), -scrollY + 480 + shake->getShakeY(), 20, 15, GetColor(0, 0, 255), TRUE, TRUE);
	DrawCircleAA(-scrollX + 830 + shake->getShakeX(), -scrollY + 870 + shake->getShakeY(), 20, 15, GetColor(0, 0, 255), TRUE, TRUE);
	DrawCircleAA(-scrollX + 1570 + shake->getShakeX(), -scrollY + 870 + shake->getShakeY(), 20, 15, GetColor(0, 0, 255), TRUE, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawLineAA(-scrollX + 32 + shake->getShakeX(), -scrollY + 0 + shake->getShakeY(), -scrollX + 2400 + shake->getShakeX(), -scrollY + 0 + shake->getShakeY(), GetColor(200, 0, 0), 61);
	DrawLineAA(-scrollX + 32 + shake->getShakeX(), -scrollY + 1350 + shake->getShakeY(), -scrollX + 2400 + shake->getShakeX(), -scrollY + 1350 + shake->getShakeY(), GetColor(200, 0, 0), 72);
	DrawLineAA(-scrollX + 2400 + shake->getShakeX(), -scrollY + 30 + shake->getShakeY(), -scrollX + 2400 + shake->getShakeX(), -scrollY + 1315 + shake->getShakeY(), GetColor(200, 0, 0), 61);
	DrawLineAA(-scrollX + 0 + shake->getShakeX(), -scrollY - 10 + shake->getShakeY(), -scrollX + 0, -scrollY + 1360 + shake->getShakeY(), GetColor(200, 0, 0), 63);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}