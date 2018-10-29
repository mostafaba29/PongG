/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include "Player.h"
#include"ball.h"
#include"Sprites.h"
#include<random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	bool p1Collision = false;
	bool p2Collision = false;
	MainWindow& wnd;
	Graphics gfx;
	std::uniform_int_distribution<int> Direction;
	Board brd;
	Player p1;
	Player p2;
	ball ball;
	Sprites s;
	bool p1Lost=false;
	bool p2Lost = false;
	int p1score=0;
	int p2score=0;
	bool GameIsStarted = false;
	bool GameIsOver = false;
	bool RoundIsOver = false;
	bool InScore = false;
	int GIOcounter=0;
	int counter = 0;
	/********************************/
	/*  User Variables              */
	/********************************/
};