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

void Player::ProgressBar(Graphics & gfx, Color c, int i,int xp,int yp)
{
	if (i == 1) {
		gfx.DrawRectDim(xp, yp, 5, 18, c);
	}
	else if (i == 2) {
		gfx.DrawRectDim(xp, yp, 5, 18, c);
		gfx.DrawRectDim(xp+8, yp, 5, 18, c);
	}
	else if (i == 3) {
		gfx.DrawRectDim(xp, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 8, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 16, yp, 5, 18, c);
	}
	else if (i == 4) {
		gfx.DrawRectDim(xp, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 8, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 16, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 24, yp, 5, 18, c);
	}
	else if (i == 5) {
		gfx.DrawRectDim(xp, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 8, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 16, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 24, yp, 5, 18, c);
		gfx.DrawRectDim(xp + 32, yp, 5, 18, c);
	}
}

void Player::reset()
{
	y = 270;
}
