#include "DxLib.h"
#include "BackGround.h"
#include "Player.h"
#include "Shake.h"
int Background::getMoveFlag() { return moveFlag; }
float Background::getWorldX() { return worldX; }
float Background::getWorldY() { return worldY; }
float Background::getScrollX() { return scrollX; }
float Background::getScrollY() { return scrollY; }
Background::Background() {
	worldX = 800, worldY = 425;
	scrollX = 400, scrollY = 225;
	startX = 600, startY = 400;
	moveFlag = 0;
	InputX = 0;
	InputY = 0;
	PadInput = 0;
}
void Background::update(char keys[255], char oldkeys[255], XINPUT_STATE* input, Player* player, Easing* easing) {
	Background::move(keys, oldkeys, input, player, easing);
}
void Background::move(char keys[255], char oldkeys[255], XINPUT_STATE* input, Player* player, Easing* easing) {
	player->setPosX(worldX - scrollX);
	player->setPosY(worldY - scrollY);
	if (keys[KEY_INPUT_RIGHT] == 1 || input->RightTrigger == 255) {
		if (worldX < 2392) {
			if (worldX - scrollX > startX && scrollX < 1600) {
				moveFlag = -1;
				scrollX += 4;
			} else {
				moveFlag = 0;
			}
			worldX += 4;
		}
	}
	if (keys[KEY_INPUT_LEFT] == 1 || input->LeftTrigger == 255) {
		if (worldX > 8) {
			if (worldX - scrollX < startX - 500 && scrollX > 0) {
				moveFlag = -1;
				scrollX -= 4;
			} else {
				moveFlag = 0;
			}
			worldX -= 4;
		}
	}
	if (keys[KEY_INPUT_UP] == 1) {
		if (worldY > 8) {
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
		if (worldY < 1342) {
			if (worldY - scrollY > startY && scrollY < 900) {
				moveFlag = 1;
				scrollY += 4;
			} else {
				moveFlag = 0;
			}
			worldY += 4;
		}
	}
}

void Background::draw(Shake* shake) {
	const int BLACK = GetColor(50, 50, 50);
	const int BACK_LENGTH = 32;
	// ”wŒi
	SetDrawBlendMode(DX_BLENDMODE_ADD, 50);
	// c
	for (int i = 0; i < 75; i++) {
		DrawLine(
			-scrollX + (i * 32) + shake->getShakeX(),
			0 + shake->getShakeY(),
			-scrollX + (i * 32) + shake->getShakeX(),
			1350 + shake->getShakeY(),
			BLACK);
	}
	// ‰¡
	for (int i = 0; i < 43; i++) {
		DrawLine(
			0 + shake->getShakeX(),
			-scrollY + (i * 32) + shake->getShakeY(),
			2400 + shake->getShakeX(),
			-scrollY + (i * 32) + shake->getShakeY(),
			BLACK);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 50);
	DrawLine(0, 0, 800, 0, GetColor(200, 0, 0), 50);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 50);
	DrawCircleAA(-scrollX + 830 + shake->getShakeX(), -scrollY + 480 + shake->getShakeY(), 20, 64, GetColor(0, 0, 255), TRUE, TRUE);
	DrawCircleAA(-scrollX + 1570 + shake->getShakeX(), -scrollY + 480 + shake->getShakeY(), 20, 64, GetColor(0, 0, 255), TRUE, TRUE);
	DrawCircleAA(-scrollX + 830 + shake->getShakeX(), -scrollY + 870 + shake->getShakeY(), 20, 64, GetColor(0, 0, 255), TRUE, TRUE);
	DrawCircleAA(-scrollX + 1570 + shake->getShakeX(), -scrollY + 870 + shake->getShakeY(), 20, 64, GetColor(0, 0, 255), TRUE, TRUE);

}