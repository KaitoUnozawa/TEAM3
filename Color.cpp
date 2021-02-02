#include "Color.h"

Color::Color() {
}

int Color::getRED2() { return RED2; }
int Color::getORANGE() { return ORANGE; }
int Color::getYELLOW() { return YELLOW; }
int Color::getGREEN() { return GREEN; }
int Color::getGREEN2() { return GREEN2; }
int Color::getGREEN3() { return GREEN3; }
int Color::getBLUE() { return BLUE; }
int Color::getBLUE2() { return BLUE2; }
int Color::getBLUE3() { return BLUE3; }
int Color::getPURPLE() { return PURPLE; }
int Color::getPURPLE2() { return PURPLE2; }
int Color::getRED() { return RED; }
int Color::getBLACK() { return BLACK; }

int Color::rainbowEngine(int cycle) {
	static int R = 0;
	static int G = 0;
	static int B = 0;

	enum rainbowFlag {
		red,
		orange,
		yellow,
		green,
		blue,
		indigo,
		violet
	};

	static int flag = red;
	static int count = 0;

	if (R == 128 && G == 0 && B == 128) { flag = violet; }
	if (R == 255 && G == 0 && B == 0) { flag = red; }
	if (R == 255 && G == 255 && B == 0) { flag = yellow; }
	if (R == 0 && G == 128 && B == 0) { flag = green; }
	if (R == 0 && G == 255 && B == 255) { flag = blue; }
	if (R == 0 && G == 0 && B == 255) { flag = indigo; }

	count++;

	if (count == cycle) {
		count = 0;

		switch (flag) {
			// red->orange->yellow
		case red:
			if (G < 255) { G++; }
			break;

		case yellow:
			// yellow->green
			if (R > 0) { R--; }
			if (G > 128) { G--; }
			if (B > 0) { B--; }
			break;

		case green:
			// green->blue
			if (G < 255) { G++; }
			if (B < 255) { B++; }
			break;

		case blue:
			// blue->indigo
			if (G > 0) { G--; }
			break;

		case indigo:
			// indigo->violet
			if (R < 128) { R++; }
			if (B > 128) { B--; }
			break;

		case violet:
			// violet->red
			if (R < 255) { R++; }
			if (B > 0) { B--; }
			break;
		}
	}

	return GetColor(R, G, B);
}