#include "Opening.h"
#include "Enemy.h"
#include"DxLib.h"
#include"Player.h"
#include "Shake.h"
#include "Color.h"

Opening::Opening() {
	OpeningX = 100;
	Gray = GetColor(224, 244, 244);
	StartCircleX = 250;
	StartCircleY = 220;
	OptionCircleX = 250;
	OptionCircleY = 285;
	EndCircleX = 250;
	EndCircleY = 355;
	Yellow = GetColor(255, 246, 127);
	Red = GetColor(230, 92, 92);
	Collid = 0;
	Active = 0;
	radius = 10;
	IsNextstage = 0;
}

Opening::~Opening() {

}
int Opening::getIsNextstage() { return IsNextstage; }

void Opening::setIsNextstage(int IsNextstage) { this->IsNextstage = IsNextstage; }

void Opening::draw(Shake* shake, Color* color) {
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	SetFontSize(25);
	DrawString(
		OpeningX + 125 + shake->getShakeX(),
		130 + shake->getShakeY(),
		"-Enclose-", Gray, GetColor(0, 0, 0));
	SetFontSize(70);
	DrawString(
		OpeningX + shake->getShakeX(),
		50 + shake->getShakeY(),
		"‰~ƒNƒ[ƒY", Gray);
	SetFontSize(40);
	DrawString(
		OpeningX + shake->getShakeX(),
		200 + shake->getShakeY(),
		"START", Gray);
	DrawString(
		OpeningX + shake->getShakeX(),
		270 + shake->getShakeY(),
		"OPTION", Gray);
	DrawString(
		OpeningX + shake->getShakeX(),
		340 + shake->getShakeY(),
		"END", Gray);
	SetFontSize(10);
	//ƒ}ƒ‹‚Ì•`‰æ
	if (Active == 1) {
		DrawCircle(
			StartCircleX + shake->getShakeX(),
			StartCircleY + shake->getShakeY(),
			radius, color->getRED2());
	}
	if (Active == 2) {
		DrawCircle(
			OptionCircleX + shake->getShakeX(),
			OptionCircleY + shake->getShakeY(),
			radius, color->getRED2());
	}
	if (Active == 3) {
		DrawCircle(
			EndCircleX + shake->getShakeX(),
			EndCircleY + shake->getShakeY(),
			radius, color->getRED2());
	}
	DrawCircle(
		StartCircleX + shake->getShakeX(),
		StartCircleY + shake->getShakeY(),
		radius, Yellow);
	DrawCircle(
		OptionCircleX + shake->getShakeX(),
		OptionCircleY + shake->getShakeY(),
		radius, Yellow);
	DrawCircle(
		EndCircleX + shake->getShakeX(),
		EndCircleY + shake->getShakeY(),
		radius, Yellow);
	DrawBox(
		200 + shake->getShakeX(),
		132 + shake->getShakeY(),
		220 + shake->getShakeX(),
		155 + shake->getShakeY(), Gray, TRUE);
	DrawBox(
		355 + shake->getShakeX(),
		132 + shake->getShakeY(),
		375 + shake->getShakeX(),
		155 + shake->getShakeY(), Gray, TRUE);
	if (Active == 1) {
		DrawCircle(
			StartCircleX + shake->getShakeX(),
			StartCircleY + shake->getShakeY(),
			radius, color->getRED2());
	}
	if (Active == 2) {
		DrawCircle(
			OptionCircleX + shake->getShakeX(),
			OptionCircleY + shake->getShakeY(),
			radius, color->getRED2());
	}
	if (Active == 3) {
		DrawCircle(
			EndCircleX + shake->getShakeX(),
			EndCircleY + shake->getShakeY(),
			radius, color->getRED2());
	}
	ChangeFontType(DX_FONTTYPE_NORMAL);
	SetFontSize(15);

}
void Opening::collide(Player* player) {
	if ((player->getPosX() - StartCircleX) * (player->getPosX() - StartCircleX) + (player->getPosY() - StartCircleY) * (player->getPosY() - StartCircleY) <= (radius + radius) * (radius + radius)) {
		Active = 1;
	} else if ((player->getPosX() - OptionCircleX) * (player->getPosX() - OptionCircleX) + (player->getPosY() - OptionCircleY) * (player->getPosY() - OptionCircleY) <= (radius + radius) * (radius + radius)) {
		Active = 2;
	} else if ((player->getPosX() - EndCircleX) * (player->getPosX() - EndCircleX) + (player->getPosY() - EndCircleY) * (player->getPosY() - EndCircleY) <= (radius + radius) * (radius + radius)) {
		Active = 3;
	} else {
		Active = 0;
	}
}
void Opening::update(char keys[255], char oldkeys[255]) {

	if (IsNextstage == 0) {
		if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
			if (Active == 1) {
				IsNextstage = 1;
			}
			if (Active == 2) {
				IsNextstage = 2;
			}
			if (Active == 3) {
				IsNextstage = 3;
			}
		}
	}

}

