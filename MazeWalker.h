/*
 * MazeWalker.h
 *
 *  Created on: May 3, 2012
 *      Author: Winnie
 */

#ifndef MAZEWALKER_H_
#define MAZEWALKER_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MazeWalker
{
public:
	char gameBoard [13][95]; //maze
	int walkerRow; //keep track of where the player is at in terms of rows
	int walkerColumn;//keep track of where the player is at in terms of columns
	char walker; //walker '@'
	char wall; //walls '#'
	char done; //all done with the maze 'D'
	int life; // keep track of how many times did '@' hit the wall before death
	char up; // up button
	char down; // down button
	char left; // left button
	char right; // right button

	MazeWalker(); //constructor
	int startMenu(); // prints game menu, gets user's choice
	char getMove(); //gets user's move
	void displayBoard(); //read board from file and prints it out
	void displayInstructions(); //displays instruction to game
	void youDumb(); //displays more instructions
	char updateMaze(bool keepGoing); //updates the maze according to user's input
	void displayUp(); //displays for up
	void displayDown(); //displays for down
	void displayRight(); //displays for right
	void displayLeft(); //displays for left

};

MazeWalker :: MazeWalker()
{
	up = 'w';
	down = 's';
	left = 'a';
	right = 'd';
	walkerRow = 2;
	walkerColumn = 3;
	walker = '@';
	wall = '#';
	done = 'D';
	life = 10;
}

//function for displaying menu and getting user's command from the menu
int MazeWalker :: startMenu()
{
	int tempUserCommandFromMenu; //temporary storage place for holding user's command

	//printout menu:
	cout << "[][][][][][][][][][][][][][][][][][]" << endl;
	cout << "[]To start ~ press 1              []" << endl;
	cout << "[]********************************[]" << endl;
	cout << "[]To end ~ press 2                []" << endl;
	cout << "[]********************************[]" << endl;
	cout << "[]How to play the game ~ press 3  []" << endl;
	cout << "[][][][][][][][][][][][][][][][][][]" << endl;

	//get user's input and put it into "tempUserCommandFromMenu":
	cin >> tempUserCommandFromMenu;

	if (tempUserCommandFromMenu == 1)
	{
		displayBoard();
	}

	else if(tempUserCommandFromMenu == 2)
	{
		cout << "Lame!!!!~ Latez~~" << endl;
	}

	else if(tempUserCommandFromMenu == 3)
	{
		displayInstructions();
	}

	else
	{
		cout << "Please use your eyes and watch what you are pressing! 1 or 2 or 3! nothing else! Jeeze" << endl;
	}
	//return it
	return tempUserCommandFromMenu;
}

void MazeWalker::displayInstructions()
{
	cout << endl;
	cout << "[][][][][][][][][][][][][][][][][][][][][][]" << endl;
	cout << "[]You are the little '@' guy! Protect him![]" << endl;
	cout << "[]Do not hurt this little guy!!!! @.@     []" << endl;
	cout << "[]                                        []" << endl;
	cout << "[]Objective:                              []" << endl;
	cout << "[]  Help '@' find his way to the exit (D) []" << endl;
	cout << "[] if it hits the wall more than 10 times []" << endl;
	cout << "[] it will die, and you would loose!      []" << endl;
	cout << "[]                                        []" << endl;
	cout << "[]Controls:                               []" << endl;
	cout << "[]                 up = w                 []" << endl;
	cout << "[]                down = d                []" << endl;
	cout << "[]                left = a                []" << endl;
	cout << "[]               right = d                []" << endl;
	cout << "[]                                        []" << endl;
	cout << "[]Tip#1: Don't hit the walls (#)!         []" << endl;
	cout << "[]Tip#2: Choose your path (- / |) wisely! []" << endl;
	cout << "[]                                        []" << endl;
	cout << "[]               You ready?               []" << endl;
	cout << "[]                Yes = 1                 []" << endl;
	cout << "[]                 No = 2                 []" << endl;
	cout << "[][][][][][][][][][][][][][][][][][][][][][]" << endl;

	int temp;
	cin >> temp;
	if (temp == 1)
	{
		displayBoard();
	}
	else if (temp == 2)
	{
		youDumb();
	}
	else
	{
		cout << "Please use your eyes and watch what you are pressing! 1 or 2 or 3! nothing else! Jeeze" << endl;
	}
}
void MazeWalker :: youDumb()
{
	cout << "[][][][][][][][][][][][][][][][][][][][][][]" << endl;
	cout << "[] FOR REALS!?!?!?!?   You dumb!?         []" << endl;
	cout << "[]                                        []" << endl;
	cout << "[] Just press 'w','a','s','d' to move '@' []" << endl;
	cout << "[] Get it to goto 'D' (the exit)          []" << endl;
	cout << "[] and try not to hit the walls ('#')     []" << endl;
	cout << "[] if you hit the wall > 10 times you die []" << endl;
	cout << "[]                                        []" << endl;
	cout << "[] Press 1 to play           or           []" << endl;
	cout << "[] Press 2 to exit                        []" << endl;
	cout << "[][][][][][][][][][][][][][][][][][][][][][]" << endl;

	int temp;
	if (temp == 1)
	{
		displayBoard();
	}

	else if(temp == 2)
	{
		cout << "Lame!!!!~ Latez~~" << endl;
	}

	else
	{
		cout << "Please use your eyes and watch what you are pressing! 1 or 2 or 3! nothing else! Jeeze" << endl;
	}
 }

void MazeWalker :: displayBoard()
{
	cout << "Off we go!~ XD" << endl;

	//get board from file
	ifstream myfile("candyBoard.txt");
	string line; // variable for getting line by line from file

	//create the board
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 95; j++)
		{
			getline(myfile, line); //get the line from file
			gameBoard[i][j] = (char)line[0];
		}
	}

	//printout board
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 95; j++)
		{
			cout << gameBoard[i][j] << " ";
		}

		cout << endl;
	}
}

char MazeWalker :: getMove()
{
	char tempDirections;
	cout << "Life: " << life << endl;
	cout << "Where are we going??" << endl;
	cin >> tempDirections;

	return tempDirections;
}

char MazeWalker :: updateMaze(bool keepGoing)
{
	char userDirections = getMove();

	if (userDirections==up)
	{
		if(gameBoard[walkerRow-1][walkerColumn] != done && gameBoard [walkerRow-1][walkerColumn] != wall)
		{
			cout << "Up we go~" << endl;
			displayUp();
			gameBoard[walkerRow][walkerColumn] = walker;
			keepGoing = true;
		}

		else if (gameBoard[walkerRow - 1][walkerColumn] == done)
		{
			displayUp();
			cout << endl;
			cout << "[][][][][][][][][][][][][][][]" << endl;
			cout << "[]You did it! You did it! :)[]" << endl;
			cout << "[][][][][][][][][][][][][][][]" << endl;
			keepGoing = false;
			cout << keepGoing<< endl;;
		}

		else if (gameBoard[walkerRow-1][walkerColumn] == wall)
		{
			//printout board
			for(int i = 0; i < 13; i++)
			{
				for(int j = 0; j < 95; j++)
				{
					cout << gameBoard[i][j] << " ";
				}

				cout << endl;
			}

			//print warning
			cout << endl;
			cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
			cout << "[]HEY!!!! You are hurting the little guy! stop hitting the wall :([]" << endl;
			cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<< endl;
			cout << endl;

			life --; // deduct life by 1
			if (life <= 0)
			{
				//print death note:
				cout << "[][][][][][][][][][][][][][][][]" << endl;
				cout << "[] Alright ASSHOLE!!!         []" << endl;
				cout << "[] You killed the little guy. []" << endl;
				cout << "[] You suck! BYE              []" << endl;
				cout << "[][][][][][][][][][][][][][][][]" << endl;
				keepGoing = false;
			}
			else
			{
				keepGoing = true;
			}
		}

	}

	else if (userDirections==down)
	{
		if (gameBoard[walkerRow+1][walkerColumn] != done && gameBoard[walkerRow+1][walkerColumn] != wall)
		{
			cout << "Down we go~" << endl;
			cout << walkerRow << " " << walkerColumn << endl;

			displayDown();

			keepGoing = true;
		}

		else if (gameBoard[walkerRow + 1][walkerColumn] == done)
		{
			displayDown();
			cout << endl;
			cout << "[][][][][][][][][][][][][][][]" << endl;
			cout << "[]You did it! You did it! :)[]" << endl;
			cout << "[][][][][][][][][][][][][][][]" << endl;
			cout << endl;

			keepGoing = false;
		}

		else if (gameBoard[walkerRow+1][walkerColumn] == wall)
		{
			//printout board
			for(int i = 0; i < 13; i++)
			{
				for(int j = 0; j < 95; j++)
				{
					cout << gameBoard[i][j] << " ";
				}

				cout << endl;
			}

			//print warning
			cout << endl;
			cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
			cout << "[]HEY!!!! You are hurting the little guy! stop hitting the wall :([]" << endl;
			cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<< endl;
			cout << endl;

			life --; // deduct life by 1
			if (life <= 0)
			{
				//print death note:
				cout << "[][][][][][][][][][][][][][][][]" << endl;
				cout << "[] Alright ASSHOLE!!!         []" << endl;
				cout << "[] You killed the little guy. []" << endl;
				cout << "[] You suck! BYE              []" << endl;
				cout << "[][][][][][][][][][][][][][][][]" << endl;
				keepGoing = false;
			}
			else
			{
				keepGoing = true;
			}
		}
	}

	else if (userDirections==left)
	{
		if (gameBoard[walkerRow][walkerColumn - 1] != done && gameBoard[walkerRow][walkerColumn -1] != wall)
		{
			cout << "Left we go~" << endl;
			displayLeft();
			gameBoard[walkerRow][walkerColumn] = walker;
			keepGoing = true;
		}

		else if (gameBoard[walkerRow][walkerColumn-1] == done)
		{
			displayLeft();
			cout << endl;
			cout << "[][][][][][][][][][][][][][][]" << endl;
			cout << "[]You did it! You did it! :)[]" << endl;
			cout << "[][][][][][][][][][][][][][][]" << endl;
			keepGoing = false;
		}

		else if (gameBoard[walkerRow][walkerColumn-1] == wall)
		{
			//printout board
			for(int i = 0; i < 13; i++)
			{
				for(int j = 0; j < 95; j++)
				{
					cout << gameBoard[i][j] << " ";
				}

				cout << endl;
			}

			// print warning
			cout << endl;
			cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
			cout << "[]HEY!!!! You are hurting the little guy! stop hitting the wall :([]" << endl;
			cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<< endl;
			cout << endl;

			life --; // deduct life by 1
			if (life <= 0)
			{
				//print death note:
				cout << "[][][][][][][][][][][][][][][][]" << endl;
				cout << "[] Alright ASSHOLE!!!         []" << endl;
				cout << "[] You killed the little guy. []" << endl;
				cout << "[] You suck! BYE              []" << endl;
				cout << "[][][][][][][][][][][][][][][][]" << endl;
				keepGoing = false;
			}
			else
			{
				keepGoing = true;
			}
		}
	}

	else if (userDirections==right)
	{
		if (gameBoard[walkerRow][walkerColumn+1] != done && gameBoard[walkerRow][walkerColumn+1] != wall)
		{
			cout << "Up we go~" << endl;
			displayRight();
			gameBoard[walkerRow][walkerColumn] = walker;
			keepGoing = true;
		}

		else if (gameBoard[walkerRow][walkerColumn+1] == done)
		{
			displayRight();
			cout << endl;
			cout << "[][][][][][][][][][][][][][][]" << endl;
			cout << "[]You did it! You did it! :)[]" << endl;
			cout << "[][][][][][][][][][][][][][][]" << endl;
			keepGoing = false;
		}

		else if (gameBoard[walkerRow][walkerColumn+1] == wall)
		{
			//printout board
			for(int i = 0; i < 13; i++)
			{
				for(int j = 0; j < 95; j++)
				{
					cout << gameBoard[i][j] << " ";
				}

				cout << endl;
			}

			//print warning
			cout << endl;
			cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]" << endl;
			cout << "[]HEY!!!! You are hurting the little guy! stop hitting the wall :([]" << endl;
			cout << "[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]"<< endl;
			cout << endl;

			life --; // deduct life by 1
			if (life <= 0)
			{
				//print death note:
				cout << "[][][][][][][][][][][][][][][][]" << endl;
				cout << "[] Alright ASSHOLE!!!         []" << endl;
				cout << "[] You killed the little guy. []" << endl;
				cout << "[] You suck! BYE              []" << endl;
				cout << "[][][][][][][][][][][][][][][][]" << endl;
				keepGoing = false;
			}
			else
			{
				keepGoing = true;
			}
		}
	}

	else if ((userDirections != up) && (userDirections != down) && (userDirections != left) && (userDirections != right))
	{
		cout << "Uh -oh, I do not understand what you want me to do" << endl;
		keepGoing = true;
	}
	return keepGoing;
}

void MazeWalker :: displayUp()
{
	gameBoard[walkerRow][walkerColumn] = ' ';
	gameBoard[walkerRow - 1][walkerColumn] = walker;

	walkerRow --;

	//printout board
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 95; j++)
		{
			cout << gameBoard[i][j] << " ";
		}

		cout << endl;
	}
}

void MazeWalker :: displayDown()
{
	gameBoard[walkerRow][walkerColumn] = ' ';
	gameBoard[walkerRow + 1][walkerColumn] = walker;

	walkerRow ++;

	//printout board
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 95; j++)
		{
			cout << gameBoard[i][j] << " ";
		}

		cout << endl;
	}
}

void MazeWalker :: displayLeft()
{
	gameBoard[walkerRow][walkerColumn] = ' ';
	gameBoard[walkerRow][walkerColumn - 1] = walker;

	walkerColumn --;

	//printout board
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 95; j++)
		{
			cout << gameBoard[i][j] << " ";
		}

		cout << endl;
	}
}

void MazeWalker :: displayRight()
{
	gameBoard[walkerRow][walkerColumn] = ' ';
	gameBoard[walkerRow][walkerColumn +1] = walker;

	walkerColumn ++;

	//printout board
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 95; j++)
		{
			cout << gameBoard[i][j] << " ";
		}

		cout << endl;
	}
}

#endif /* MAZE_H_ */
