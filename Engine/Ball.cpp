#include "Ball.h"
ball::ball()
	:
	x(400),
	y(300),
	vx(1),
	vy(1)
{
}

void ball::Draw(Color c,Graphics& gfx)
{
	int r = 100;
	for (int y_loop=y-10; y_loop < y+10; y_loop++) {
		for (int x_loop = x-10; x_loop < x+10; x_loop++) {
			const int x_diff = x - x_loop;
			const int y_diff = y - y_loop;
			if ((x_diff*x_diff) + (y_diff*y_diff) <= r) {
				gfx.PutPixel(x_loop, y_loop, c);
			}
		}
	}
}

/*void ball::Init()
{
	for (int i = 0; i < 221; i++) {
		x -= vx;
	}
}*/

void ball::IncreaseSpeed()
{
	vx++;
	vy++;
}

void ball::ClambBoard()
{
	if ((x+10 > 649) || (x-10 < 151)) {
		vx = 0;
		vy = 0;
	}
	if ((y+10 > 549) || (y-10 < 51)) {
		vy = -vy;
	}
}

void ball::Update(int Yc,Player& p)
{
	if (x <= 400) {
		if (CheckCollision1(p)) {
			if ((y > Yc - 30) && (y < Yc - 10)) {
				vy = -vy;
				vx = -vx;
			}
			else if ((y <= Yc + 10) && (y >= Yc - 10)) {
				vy = 0;
				vx = -vx;
			}
			else if ((y > Yc + 10) && (y < Yc + 30)) {
				vy = -vy;
				vx = -vx;
			}
		}
	}
	if (x > 400) {
		if (CheckCollision2(p)) {
			if ((y > Yc - 30) && (y < Yc - 10)) {
				vx = -vx;
				vy = -vy;
			}
			else if ((y <= Yc + 10) && (y >= Yc - 10)) {
				vx = -vx;
				vy = 0;
			}
			else if ((y > Yc + 10) && (y < Yc + 30)) {
				vx = -vx;
				vy = -vy;
			}
		}
	}
	x += vx;
	y += vy;
}

int ball::GetPosY()
{
	return y;
}

bool ball::CheckCollision1(Player& p)
{
	return (x - 10) <= 170;
}

bool ball::CheckCollision2(Player & p)
{
	return (x + 10) >= 630;
}
