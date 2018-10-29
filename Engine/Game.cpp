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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	rng(rd())
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
	ball.Update(p1.GetY(), p1);
	ball.Update(p2.GetY(), p2);
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
}

void Game::ComposeFrame()
{
	p1.Draw(Colors::Red, gfx, 630);
	p2.Draw(Colors::Blue, gfx, 151);
	ball.Draw(Colors::White, gfx);
	brd.DrawBorder(150, 50, gfx, Colors::White);
	
}
