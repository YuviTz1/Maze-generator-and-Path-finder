#pragma once
#include"platform.h"
#include"buffer.h"

using namespace std;

class SimpleMaze
{
public:

	platform sdl;
	int n = 100;
	int** maze = new int* [n];
	int dir = NULL;
	int dec = NULL;
	int* screen = new int[n * n];	

	SimpleMaze()
	{
		for (int i = 0; i < n; i++)
		{
			maze[i] = new int[n];
		}

		//initialise
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maze[i][j] = 0;
			}
		}		

		maze[0][0] = 1;
		clearBuffer(screen, n);
	}

	~SimpleMaze()
	{
		delete[] maze;
		delete[] screen;
	}

	int random()
	{
		return(rand() % 2 + 1);
	}

	//very crude algorithm for generating a maze
	//doesn't always generate a path from start to finish
	void create()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dir = random();
				if (dir == 1)
				{
					if (j + 1 < n)
					{
						if (maze[i][j + 1] == 0)
						{
							maze[i][j + 1] = 1;
						}
						else if (maze[i][j + 1] == 1)
						{
							dec = random();
							if (dec == 2)
							{
								maze[i][j] = 0;
							}
						}
					}
					buffer(screen, n, maze);
					sdl.update(screen);
					clearBuffer(screen, n);

					//std::this_thread::sleep_for(0.01s);
				}
				else if (dir == 2)
				{
					if (i == n - 1)
					{
						if (j + 1 <= n - 1)
						{
							maze[i][j + 1] = 1;
						}
					}
					//check and move down
					else if (i + 1 < n)
					{
						if (maze[i + 1][j] == 0)
						{
							maze[i + 1][j] = 1;
						}
						else if (maze[i + 1][j] == 1)
						{
							dec = random();
							if (dec == 2)
							{
								maze[i][j] = 0;
							}
						}
					}
					buffer(screen, n, maze);
					sdl.update(screen);
					clearBuffer(screen, n);

					//std::this_thread::sleep_for(0.01s);
				}
			}
		}
	}	
};