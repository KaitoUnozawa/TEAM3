#include "RainbowEngine.h"
#include "DxLib.h"

int RainbowEngine::rainbowEngine(int cycle) {
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