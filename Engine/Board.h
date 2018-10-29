#pragma once
#include"Graphics.h"
class Board {
public:
	Board(Graphics& gfx);
	void DrawBorder(int x, int y, Graphics& gfx);
	const int GetWidth()const;
	const int GetHeight()const;
	void ChangeColor();
	//bool IsInside(const Location& loc)const;
private:
	//Location Loc;
	Color c=Colors::White;
	static constexpr int Width = 35;
	static constexpr int Height = 25;
	static constexpr int Dim = 20;
	Graphics& gfx;
};