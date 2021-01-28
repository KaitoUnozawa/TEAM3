#pragma once

class Easing {
private:
	int start;	// 開始
	int end;	// 終了
	int movPix;	// 移動量
	int priPos;	// 初期位置

public:
	// コンストラクタ
	Easing();

	int getStart();
	int getEnd();
	int getMovPix();
	int getPriPos();
	float getEaseNum();

	void setStart(int start);
	void setEnd(int end);
	void setMovPix(int movPix);
	void setPriPos(int priPos);
	void setEaseNum(float easeNum);

	float easeMove(int priPos, int movPix, int easingType);

	float easeInQuint(float frame, float maxFrame);
	float easeOutQuint(float frame, float maxFrame);
	float easeInOutQuint(float frame, float maxFrame);
	float easeInCirc(float frame, float maxFrame);
	float easeInBack(float frame, float maxFrame);
	float easeInExpo(float frame, float maxFrame);
	float easeOutBack(float frame, float maxFrame);
	float easeOutBounce(float frame, float maxFrame);
};