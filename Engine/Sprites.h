#pragma once
#include"Graphics.h"
class Sprites {
public:
	void DrawPressEnter(Graphics& gfx);
	void DrawGameOver( Graphics& gfx);
private:
	int x=300;
	int y=300;
};