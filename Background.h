#pragma once
#include "DxLib.h"
#include "Easing.h"

class Player;
class Shake;
class Color;


class Background {
private:
	float worldX, worldY;
	float scrollX, scrollY;
	int startX, startY;
	int moveFlag;
	int InputX, InputY;
	int PadInput;
	int alpha;
	int count;
	int angle;

public:
	Background();
	float getWorldX();
	float getWorldY();
	float getScrollX();
	float getScrollY();
	int getMoveFlag();
	void setworldX(int worldX);
	void setworldY(int worldY);
	void setscrollX(int scrollX);
	void setscrollY(int scrollY);
	void update(char keys[255], char oldkeys[255], Player* player, Easing* easing);
	void move(char keys[255], char oldkeys[255],  Player* player, Easing* easing);
	void draw(Shake* shake, Color* color);
};