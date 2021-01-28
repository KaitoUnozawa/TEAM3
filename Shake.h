#pragma once
class Shake {
private:
	int shake[2];
	int intensify;

public:
	Shake();

	int getShakeX();
	int getShakeY();
	void setIntensify(int intensify);

	void shaking();
};