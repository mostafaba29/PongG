#include "Ball.h"
ball::ball()
	:
	x(400),
	y(300),
	vx(3),
	vy(3)
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

void ball::ClambBoard()
{
	if (x+10 > 749) {
		vx = 0;
		vy = 0;
		p1lost = true;
	}
	if (x -10 < 51) {
		vx = 0;
		vy = 0;
		p2lost = true;
	}
	if ((y+10 > 549) || (y-10 < 51)) {
		vy = -vy;
	}
}

void ball::Update(int Yp1, int Yp2,bool p1,bool p2,int r)
{
	if (p1 && (GetPosY() > Yp1 - 40) && (GetPosY() < Yp1 + 40)) {
			vx = -vx;
			vy = -vy*r;
	}
	else if (p2 && (GetPosY() > Yp2 - 40) && (GetPosY() < Yp2 + 40)) {
			vx = -vx;
			vy = -vy*r; 
	}
	x += vx;
	y += vy;
}

int ball::GetPosY()
{
	return y;
}

bool ball::GetLost1() const
{
	return p1lost;
}

bool ball::GetLost2() const
{
	return p2lost;
}

bool ball::CheckCollision1(Player& p)
{
	return (x + 10) >= 728;
}

bool ball::CheckCollision2(Player & p)
{
	return (x - 10) <= 73;
}

void ball::reset()
{
	x = 400;
	y = 300;
	vx = 3;
	vy = 3;
	p1lost = false;
	p2lost = false;
}
