#include "Option.h"
#include"DxLib.h"
#include"Player.h"

Option::Option() {
	Theme = 1;
	VolumeActive = 0;
	Volume = 50;
	posx =400;
	posy = 325;
	radius = 10;
	Red = GetColor(220, 0, 0);
	Gray = GetColor(125, 125, 125);
	Green = GetColor(100, 200, 200);
	Black = GetColor(0, 0, 0);
	BackTitle = 0;
}

int Option::getTheme() { return Theme; }
int Option::getVolume() { return Volume; }
int Option::getBackTitle() { return BackTitle; }

void Option::setBackTitle(int BackTitle) { this->BackTitle = BackTitle; }

void Option::draw() {
	DrawLine(230, posy, 570, posy, GetColor(220, 220, 220), 5);
	DrawBoxAA(posx - radius, posy - radius, posx + radius, posy + radius, Green, TRUE);
	DrawBox(225, 300, 240, 350, Gray, TRUE);//左の四角形
	DrawBox(560, 300, 575, 350, Gray, TRUE);//右の四角形
	SetFontSize(15);
	if (VolumeActive == 1)
	{
		DrawFormatString(posx - radius * 2, posy - 25, Red, "<-", Volume, TRUE);
	}
	if (VolumeActive == 2)
	{
		DrawFormatString(posx, posy - 25, Red, "->", Volume, TRUE);
	}
	if (VolumeActive == 0)
	{
		DrawFormatString(posx - radius * 2, posy - 25, Gray, "<-", Volume, TRUE);
		DrawFormatString(posx, posy - 25, Gray, "->", Volume, TRUE);
	}
	
	if (Theme == 1)
	{
		DrawBox(280, 130, 320, 170, Red, false);
		DrawBox(480, 130, 520, 170, Black, false);
		SetFontSize(20);
		DrawFormatString(295, 140, Red, "1", TRUE);
		DrawFormatString(495, 140, Black, "2", TRUE);

	}
	if (Theme == 2)
	{
		DrawBox(280, 130, 320, 170, Black, false);
		DrawBox(480, 130, 520, 170, Red, false);
		SetFontSize(20);
		DrawFormatString(295, 140, Black, "1", TRUE);
		DrawFormatString(495, 140, Red, "2", TRUE);
	}
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	SetFontSize(30);
	DrawFormatString(225, 250, Gray, "VOLUME  %d", Volume, TRUE);
	DrawFormatString(225, 50, Gray, "THEME  %d", Theme, TRUE);
	DrawFormatString(225, 50, Gray, "THEME  %d", Theme, TRUE);
	DrawFormatString(225, 50, Gray, "THEME  %d", Theme, TRUE);
	DrawFormatString(225,400, Gray, "TITLE T", TRUE);
}
void Option::update(char keys[255], char oldkeys[255], Player* player) {
	if (keys[KEY_INPUT_1] == 1)
	{
		Theme = 1;
	}
	if (keys[KEY_INPUT_2] == 1)
	{
		Theme = 2;
	}

	if (keys[KEY_INPUT_LEFT] == 1)
	{
		if (Volume > 0)
		{
			Volume--;
			posx -= 3;
			VolumeActive = 1;
		}
	} else if (keys[KEY_INPUT_RIGHT] == 1)
	{
		if (Volume < 100)
		{
			Volume++;
			posx += 3;
			VolumeActive = 2;
		}

	} else
	{
		VolumeActive = 0;
	}
}



