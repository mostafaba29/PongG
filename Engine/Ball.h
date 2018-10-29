#pragma once
#include<random>
#include"Graphics.h"
#include"Player.h"
class ball {
public:
	ball();
	void Draw(Color c, Graphics& gfx);
	void Init();
	void IncreaseSpeed();
	void ClambBoard();
	void Update(int Yc,Player& p);
	int GetPosY();
	bool CheckCollision1(Player& p);
	bool CheckCollision2(Player& p);
private:
	int x;
	int y;
	int vx;
	int vy;
};