#pragma once

#include<stack>
#include<thread>
#include<chrono>
#include"buffer.h"
#include"platform.h"

using namespace std;


class BacktrackPathfinder
{
public:

	int n = 100;
	bool** visited = new bool* [n];
	
	struct cell
	{
		int x;
		int y;
	};

	stack<cell> reverseStack(stack<cell> s)
	{
		stack<cell> p;
		cell temp;
		while (!s.empty())
		{
			temp = s.top();
			p.push(temp);
			s.pop();
		}
		return p;
	}

	void pathReflect(int* buffer, int n, stack<cell> s)
	{
		stack<cell> p = reverseStack(s);

		while (!p.empty())
		{
			cell c = p.top();
			int x = c.x;
			int y = c.y;
			buffer[y * n + x] = 0x000000ff;
			p.pop();
		}

	}

	BacktrackPathfinder()
	{
		
		for (int i = 0; i < n; i++)
		{
			visited[i] = new bool[n];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = 0;
			}
		}
	}

	~BacktrackPathfinder()
	{
		delete[] visited;
	}

	void find(int** maze, int screen[], platform sdl)
	{
		stack<cell> s;
		cell c = { 0, 0 };
		s.push(c);
		visited[0][0] = 1;
		bool finished = false;
		bool found = false;
		bool pathFound = false;

		while (finished == false)
		{
			cell curr = s.top();
			int x = curr.x;
			int y = curr.y;
			found = false;

			if (x == n - 1)
			{
				if (y == n - 1)
				{
					finished = true;
					pathFound = true;
				}
			}

			//right
			if (x + 1 <= n - 1)
			{
				if (found == false)
				{
					if (maze[y][x + 1] == 1)
					{
						if (visited[y][x + 1] == 0)
						{
							c = { x + 1,y };
							s.push(c);
							visited[y][x + 1] = 1;
							found = true;

							buffer(screen, n, maze);
							pathReflect(screen, n, s);
							sdl.update(screen);
							clearBuffer(screen, n);
							std::this_thread::sleep_for(0.01s);

						}
					}
				}
			}
			//down
			if (y + 1 <= n - 1)
			{
				if (found == false)
				{
					if (maze[y + 1][x] == 1)
					{
						if (visited[y + 1][x] == 0)
						{
							c = { x,y + 1 };
							s.push(c);
							visited[y + 1][x] = 1;
							found = true;
							buffer(screen, n, maze);
							pathReflect(screen, n, s);
							sdl.update(screen);
							clearBuffer(screen, n);
							std::this_thread::sleep_for(0.01s);

						}
					}
				}
			}
			//left
			if (x - 1 >= 0)
			{
				if (found == false)
				{
					if (maze[y][x - 1] == 1)
					{
						if (visited[y][x - 1] == 0)
						{
							c = { x - 1,y };
							s.push(c);
							visited[y][x - 1] = 1;
							found = true;
							buffer(screen, n, maze);
							pathReflect(screen, n, s);
							sdl.update(screen);
							clearBuffer(screen, n);
							std::this_thread::sleep_for(0.01s);

						}
					}
				}
			}
			//up
			if (y - 1 >= 0)
			{
				if (found == false)
				{
					if (maze[y - 1][x] == 1)
					{
						if (visited[y - 1][x] == 0)
						{
							c = { x ,y - 1 };
							s.push(c);
							visited[y - 1][x] = 1;
							found = true;
							buffer(screen, n, maze);
							pathReflect(screen, n, s);
							sdl.update(screen);
							clearBuffer(screen, n);
							std::this_thread::sleep_for(0.01s);

						}
					}
				}
			}
			if (found == false)
			{
				s.pop();
				buffer(screen, n, maze);
				pathReflect(screen, n, s);
				sdl.update(screen);
				clearBuffer(screen, n);
				std::this_thread::sleep_for(0.01s);
				if (s.empty() == true)
				{
					finished = true;
				}
			}
		}
		if (pathFound == true)
		{
			cout << "Path generated" << endl;
		}
		else
		{
			cout << "Path not found" << endl;
		}
		cin.get();
	}
};
