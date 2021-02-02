#pragma once
#include "DxLib.h"
#include "GameObject.h"
class Easing;
class SceneTransition;
class Color;

class Select : GameObject {
private:
	const float WIN_WIDTH = 800.0f;
	const float WIN_HEIGHT = 450.0f;

	int priPosX = static_cast<int>(WIN_WIDTH);
	int priPosY = static_cast<int>(WIN_HEIGHT);

	float speedX;
	float speedY;
	int angle;

	int speed;

	int index;
	//int count;
	int frame;

	const int BLACK = GetColor(0, 0, 0);
	int color;
public:
	Select();

	void update(SceneTransition* scene_transition, Easing* easing, Color* color, int index);
	void makeAngle(Color* color,int index);
	void moveCircle(Easing* easing);
	void draw();
};