#include <iostream>

void mazeCreator(int maze[100][100], int size);
void mazePrint(int maze[100][100], int size);

int main()
{
	int x {0};
	int maze[100][100];
	
    std::cout << "This is going to be a Maze Creator program!\n";
	std::cout << "Type in a maze dimensions:\n";

	std::cin >> x;

	std::cout << "Your Maze will be a size of: " << x << "x" << x << "\n";

	mazeCreator(maze, x);
	mazePrint(maze, x);

	return 0;
}


static void mazeCreator(int maze[100][100], int size)
{
	for (int i = 0; i < 100; i++)
	{
		if (i < size) {
			for (int j = 0; j < 100; j++)
			{
				//Borders of the maze
				if (i == 0 || i == size-1 || j == 0 || j == size-1)
				{
					maze[i][j] = 3;
				} else if (j < size) {
					maze[i][j] = 1;
				}
				else maze[i][j] = 0;
			}
		}
		
	}
}

static void mazePrint(int maze[100][100], int size)
{
	for(int i = 0; i < size; i++)
		{
		for(int j = 0; j < size; j++)
		{
			if (maze[i][j] == 1)
			{
				std::cout << maze[i][j] << " ";
			}
			else if (maze[i][j] == 3)
			{
				std::cout << "#";
			}
		}
		std::cout << "\n";
	}
}


