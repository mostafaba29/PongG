#pragma once
#include"Graphics.h"
class Board {
public:
	Board(Graphics& gfx);
	void DrawBorder(int x, int y, Graphics& gfx, Color C);
	const int GetWidth()const;
	const int GetHeight()const;
	//bool IsInside(const Location& loc)const;
private:
	//Location Loc;
	static constexpr int Width = 25;
	static constexpr int Height = 25;
	static constexpr int Dim = 20;
	Graphics& gfx;
};