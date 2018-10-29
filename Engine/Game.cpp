/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(rd()),
	Direction(0, 1)
{
	//ball.Init();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!GameIsStarted) {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) { GameIsStarted = true; }
	}
	else if (GameIsStarted&&!GameIsOver) {
		int p1y = p1.GetY();
		int p2y = p2.GetY();
		p1Collision = ball.CheckCollision1(p1);
		p2Collision = ball.CheckCollision2(p2);
		ball.Update(p1y, p2y, p1Collision, p2Collision, Direction(rng));
		ball.ClambBoard();
		if (wnd.kbd.KeyIsPressed(VK_UP)) {
			p1.Move('u');
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
			p1.Move('d');
		}
		if (wnd.kbd.KeyIsPressed('W')) {
			p2.Move('u');
		}
		if (wnd.kbd.KeyIsPressed('S')) {
			p2.Move('d');
		}
		Lost = ball.GetLost();
	}

}

void Game::ComposeFrame()
{
	if (!GameIsStarted) {
		s.DrawPressEnter(gfx);
	}
	else if (GameIsStarted) {
		p1.Draw(Colors::Green, gfx, 730);
		p2.Draw(Colors::Blue, gfx, 51);
		ball.Draw(Colors::White, gfx);
		if (Lost) {
			brd.ChangeColor();
			GameIsOver = true;
		}
		brd.DrawBorder(50, 50, gfx);
	}
	else if(GameIsOver){
		s.DrawGameOver2(gfx);
	}
}
