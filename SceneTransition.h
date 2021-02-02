#pragma once
#include "GameObject.h"

class Player;
class Easing;
class Color;

class SceneTransition : GameObject {
private:
	int priPos;
	int movPix;
	bool isIncreaseOver;
	bool isOver;

public:
	SceneTransition();

	int getIsIncreaseOver();
	int getIsOver();

	void update(Player* player, Easing* easing);
	void increase(Player* player, Easing* easing);
	void decrease(Player* player, Easing* easing);
	void draw(Color* color);
};