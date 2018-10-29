#include "Player.h"

void Player::Draw(Color c,Graphics& gfx,int z)
{
	x=z;
	gfx.DrawRectDim(x, y, 20, 60, c);
}

void Player::Move(char c)
{
	if (c == 'u') {
		y -= vy;
	}
	else if (c == 'd') {
		y += vy;
	}
}

int Player::GetY()
{
	return y;
}

int Player::GetX()
{
	return x;
}
