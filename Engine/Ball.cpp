#include "Ball.h"
ball::ball()
	:
	x(400),
	y(300),
	vx(2),
	vy(2)
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
	if ((x+10 > 749) || (x-10 < 51)) {
		vx = 0;
		vy = 0;
		lost = true;
	}
	if ((y+10 > 549) || (y-10 < 51)) {
		vy = -vy;
	}
}

void ball::Update(int Yp1, int Yp2,bool p1,bool p2,int r)
{
	if (p1 && (GetPosY() > Yp1 - 35) && (GetPosY() < Yp1 + 35)) {
			/*if (r == 0) {
				vx = -vx;
				vy = -vy;
			}
			else if (r == 1) {
				vx = -vx;
				vy = vy;
			}*/
			vx = -vx;
			vy = -vy;
	}
	else if (p2 && (GetPosY() > Yp2 - 35) && (GetPosY() < Yp2 + 35)) {
			/*if (r == 0) {
				vx = -vx;
				vy = -vy;
			}
			else if (r == 1) {
				vx = -vx;
				vy = vy;
			}*/
			vx = -vx;
			vy = -vy;
	}
	x += vx;
	y += vy;
}

int ball::GetPosY()
{
	return y;
}

bool ball::GetLost() const
{
	return lost;
}

bool ball::CheckCollision1(Player& p)
{
	return (x + 10) >= 730;
}

bool ball::CheckCollision2(Player & p)
{
	return (x - 10) <= 71;
}
