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
	Direction(-1, 1)
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
	std::random_device rd;
	std::mt19937 rng(rd());
	if (!GameIsStarted) {
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) { GameIsStarted = true; }
	}
	else if (RoundIsOver) {
		if (!(InScore)) {
			if (p1Lost)p2score++;
			if (p2Lost)p1score++;
			InScore = true;
			if (p1score == 5 || p2score == 5)GameIsOver = true;
		}
		GIOcounter++;
		if (GIOcounter >= 120) {
			GIOcounter = 0;
			ball.reset();
			p1.reset();
			p2.reset();
			brd.Wcolor();
			RoundIsOver = false;
			InScore = false;
		}
	}
	else if (GameIsStarted&&!GameIsOver&&!RoundIsOver) {
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
		p1Lost = ball.GetLost1();
		p2Lost = ball.GetLost2();
		if (p1Lost || p2Lost) RoundIsOver = true;
	}
	
	//p1.ProgressBar(gfx, Colors::Green, 5, 50, 10);
}

void Game::ComposeFrame()
{
	if (!GameIsStarted) {
		s.DrawPressEnter(gfx);
	}
	else if (GameIsStarted&&!GameIsOver) {
		p1.Draw(Colors::Green, gfx, 730);
		p2.Draw(Colors::Blue, gfx, 51);
		ball.Draw(Colors::White, gfx);
		p1.ProgressBar(gfx, Colors::Blue, p2score, 50, 10);
		p2.ProgressBar(gfx, Colors::Green, p1score, 718, 10);
		if (RoundIsOver) {
			brd.ChangeColor();
		}
		brd.DrawBorder(50, 50, gfx);
	}
	else if (GameIsOver) {
		s.DrawGameOver(gfx);
	}
	
}
