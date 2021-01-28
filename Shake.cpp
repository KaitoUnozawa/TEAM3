#include "Shake.h"
#include "DxLib.h"

Shake::Shake() {
	shake[0] = 0;
	shake[1] = 0;
	intensify = 0;
}

int Shake::getShakeX() { return shake[0]; }
int Shake::getShakeY() { return shake[1]; }

void Shake::setIntensify(int intensify) { this->intensify = intensify; }

void Shake::shaking() {
	if (intensify >= 0) {
		for (int i = 0; i < 2; i++) {
			shake[i] = GetRand(intensify * 2) - intensify;
		}
	}
	intensify--;
}