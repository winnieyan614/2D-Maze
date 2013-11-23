/*
 * Maze.cpp
 *
 *  Created on: May 2, 2012
 *      Author: Winnie
 */

#include <iostream>
#include <fstream> // this is for read from file
#include <string>
#include "MazeWalker.h"

using namespace std;

int main()
{

	bool keepGoing = true;

	MazeWalker mw = MazeWalker();
	mw.startMenu();

	while (keepGoing == true)
	{
		mw.updateMaze(keepGoing);
	}
}

