#pragma once
void clearBuffer(int* buffer, int n)
{
	for (int i = 0; i < n * n; i++)
	{
		buffer[i] = 0x00000000;
	}
}

void buffer(int* buffer, int n, int** maze)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maze[i][j] == 1)
			{
				buffer[i * n + j] = 0x00ffffff;
			}
		}
	}
}