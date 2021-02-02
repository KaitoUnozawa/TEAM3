#include "easing.h"
#include <cmath>

Easing::Easing() {
	priPos = 0;
	start = 0;
	end = 50;
	movPix = 100;
}

int Easing::getStart() { return start; }
int Easing::getEnd() { return end; }
int Easing::getMovPix() { return movPix; }
int Easing::getPriPos() { return priPos; }

void Easing::setStart(int start) { this->start = start; }
void Easing::setEnd(int end) { this->end = end; }
void Easing::setMovPix(int movPix) { this->movPix = movPix; }
void Easing::setPriPos(int priPos) { this->priPos = priPos; }

float Easing::easeMove(int priPos, int movPix, int easingType) {
	float pos;
	float x[10];
	static int frame[10] = { 0 };
	const int MAX_FRAME = 50;

	if (easingType == 0) {
		// easeOutQuint
		if (frame >= 0 && frame[0] <= MAX_FRAME) {
			x[0] = frame[0] / MAX_FRAME;
			frame[0]++;

			return pos = priPos + movPix * (1 - pow(1 - x[0], 5));
		}
	}
}

float Easing::easeInQuint(float start, float end) {
	float x;
	x = start / end;

	return pow(x, 5);
}

float Easing::easeOutQuint(float start, float end) {
	float x;
	x = start / end;

	return 1 - pow(1 - x, 5);
}

float Easing::easeInOutQuint(float start, float end) {
	double x;
	x = start / end;

	return x < 0.5 ? x * (16 * x) * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}

float Easing::easeInCirc(float start, float end) {
	float x;
	x = start / end;

	return 1 - sqrt(1 - pow(x, 2));
}

float Easing::easeInBack(float start, float end) {
	float x;
	x = start / end;

	const float c1 = 1.70158;
	const float c3 = c1 + 1;

	return c3 * x * x * x - c1 * x * x;
}

float Easing::easeInExpo(float frame, float maxFrame) {
	float x;
	x = frame / maxFrame;

	return x = 0 ? 0 : pow(2, 10 * x - 10);
}

float Easing::easeOutBack(float start, float end) {
	float x;
	x = start / end;

	const float c1 = 1.70158;
	const float c3 = c1 + 1;

	return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}

float Easing::easeOutBounce(float start, float end) {
	float x;
	x = start / end;

	const float n1 = 7.5625;
	const float d1 = 2.75;

	if (x < 1 / d1) {
		return n1 * x * x;
	} else if (x < 2 / d1) {
		return n1 * (x -= 1.5 / d1) * x + 0.75;
	} else if (x < 2.5 / d1) {
		return n1 * (x -= 2.25 / d1) * x + 0.9375;
	} else {
		return n1 * (x -= 2.625 / d1) * x + 0.984375;
	}
}