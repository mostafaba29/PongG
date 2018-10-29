#pragma once
#include"Graphics.h"
class Player {
public:
	void Draw(Color c, Graphics& gfx, int z);
	void Move(char c);
	int GetY();
	int GetX();
	void ProgressBar(Graphics&gfx,Color c,int i, int xp, int yp);
	void reset();
private:
	int x;
	int y=270;
	int vy=3;
};