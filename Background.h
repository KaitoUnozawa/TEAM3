#pragma once
#include "DxLib.h"
#include "Easing.h"

class Player;
class Shake;

class Background {
private:
	float worldX, worldY;
	float scrollX, scrollY;
	int startX, startY;
	int moveFlag;
	int InputX, InputY;
	int PadInput;
public:
	Background();
	float getWorldX();
	float getWorldY();
	float getScrollX();
	float getScrollY();
	int getMoveFlag();
	void update(char keys[255], char oldkeys[255], XINPUT_STATE* input, Player* player, Easing* easing);
	void move(char keys[255], char oldkeys[255], XINPUT_STATE* input, Player* player, Easing* easing);
	void draw(Shake* shake);
};