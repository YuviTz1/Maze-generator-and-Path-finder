#include<iostream>
#include"buffer.h"
#include"SimpleMaze.h"
#include"BackTrackPathfinder.h"

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));
	
	SimpleMaze smaze;
	smaze.create();

	cout << "Maze Generated" << endl;
	cin.get();
	
	BacktrackPathfinder path;
	path.find(smaze.maze, smaze.screen, smaze.sdl);	

	return EXIT_SUCCESS;
}