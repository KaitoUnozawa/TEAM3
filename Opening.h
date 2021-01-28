#pragma once
#include"GameObject.h"

class Player;

class Opening :public GameObject{
private:
	int OpeningX;
	int Gray;
	int StartCircleX;
	int StartCircleY;
	int OptionCircleX;
	int OptionCircleY;
	int EndCircleX;
	int EndCircleY;
	int Yellow;
	int Red;
	int Collid;
	int Active;
	int radius;
	int IsNextstage;
public:
	Opening();
	~Opening();
	//void update(char keys[255], char oldkeys[255],int scene);
	int getIsNextstage();

	void setIsNextstage(int IsNextstage);

	void update(char keys[255], char oldkeys[255]);
	void collide(Player* player);
	void draw();
};

