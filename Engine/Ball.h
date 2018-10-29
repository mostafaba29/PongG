#pragma once
#include<random>
#include"Graphics.h"
#include"Player.h"
class ball {
public:
	ball();
	void Draw(Color c, Graphics& gfx);
	void Init();
	void ClambBoard();
	void Update(int Yp1, int Yp2, bool p1, bool p2, int r);
	int GetPosY();
	bool GetLost1()const;
	bool GetLost2()const;
	bool CheckCollision1(Player& p);
	bool CheckCollision2(Player& p);
	void reset();
private:
	int x;
	int y;
	int vx;
	int vy;
	bool p1lost=false;
	bool p2lost = false;
	std::mt19937 dir;
	std::random_device rd;
};