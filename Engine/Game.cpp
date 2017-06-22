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
	//rng(std::random_device()()),
	snake(locStart),
	food(locStart)
{
	
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
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		delta_loc = { 0,1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		delta_loc = { 0,-1 };
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		delta_loc = { 1,0 };
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		delta_loc = { -1,0 };
	}
	if (!isGameOver) {
		if (counter > snakeSpeed)
		{
			if (!brd.isInsideBoard(snake.GetNextHeadLocation(delta_loc))) {
				isGameOver = true;
			}
			if (snake.isSelfEaten()) {
				isGameOver = true;
			}
			if (brd.isEating(snake.GetNextHeadLocation(delta_loc), food.getLoc())) {
				food.Update(brd);
				snake.Grow();
				score++;
			}
			
			if (!isGameOver)
			{
				if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
					snake.Grow();
				}
				snake.MoveBy(delta_loc);
				counter = 0;
			}
		}
		counter++;
	}

	
	
}

void Game::ComposeFrame()
{
	food.Draw(brd);
	snake.Draw(brd);

}
