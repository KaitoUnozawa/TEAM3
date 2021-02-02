#pragma once
class Player;

class Option{
private:
	int Theme;
	int VolumeActive;
	int Volume;
	int posx;
	int posy;
	int radius;
	int Red;
	int Gray;
	int Green;
	int Black;
	int BackTitle;
		
public:
	Option();

	int getTheme();
	int getVolume();
	int getBackTitle();
	void setBackTitle(int BackTitle);

	void update(char keys[255], char oldkeys[255], Player* player);
	void draw();

};

