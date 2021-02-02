#pragma once
#include "DxLib.h"

class Color {
private:
	const int RED2 = GetColor(0xde, 0x56, 0x41);
	const int ORANGE = GetColor(0xe8, 0xac, 0x51);
	const int YELLOW = GetColor(0xf2, 0xe5, 0x5c);
	const int GREEN = GetColor(0xaa, 0xcb, 0x63);
	const int GREEN2 = GetColor(0x39, 0xa8, 0x69);
	const int GREEN3 = GetColor(0x27, 0xac, 0xa9);
	const int BLUE = GetColor(0x47, 0x84, 0xbf);
	const int BLUE2 = GetColor(0x47, 0x84, 0xbf);
	const int BLUE3 = GetColor(0x5d, 0x50, 0x99);
	const int PURPLE = GetColor(0xa5, 0x5b, 0x9a);
	const int PURPLE2 = GetColor(0xdc, 0x66, 0x9b);
	const int RED = GetColor(0xdd, 0x66, 0x73);
	const int BLACK = GetColor(50, 50, 50);

public:
	Color();

	int getRED2();
	int getORANGE();
	int getYELLOW();
	int getGREEN();
	int getGREEN2();
	int getGREEN3();
	int getBLUE();
	int getBLUE2();
	int getBLUE3();
	int getPURPLE();
	int getPURPLE2();
	int getRED();
	int getBLACK();

	int rainbowEngine(int cycle);
};