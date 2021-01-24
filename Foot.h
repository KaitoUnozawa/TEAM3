#pragma once
#include"GameObject.h"
#include "BackGraoud.h"

class Foot {
private:
	float posX, posY, radius;
	int bright,isVisible;
public:
	Foot();
	int getIsVisible();
	void prepare(BackGraoud* backgraoud);
	void visible();
	void draw();
};