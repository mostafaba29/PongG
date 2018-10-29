#pragma once
#include"Graphics.h"
class Player {
public:
	void Draw(Color c, Graphics& gfx, int z);
	void Move(char c);
	int GetY();
	int GetX();
private:
	int x;
	int y=270;
	int vy=3;
};