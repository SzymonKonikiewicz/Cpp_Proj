#include <iostream>
#include <cstdlib>

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
	bool flag{ true };
	bool path{ true };
	int x{size - 2};
	int y{size / 2};
	int r{ 0 };
	int dir{ 3 };
	int pom{ 0 };

#if 0
	My made up rules to the creation of the maze which will make it pretty :) (hopefully) :
	1. Surrounded by walls //done
	2. Has one entrance and one exit //entrance done
	3. There is never a situation where a 4x4 block of walls is created at a border of a maze
	4. Maze consists of ONLY a 1 tile wide corridors
	5. Maze is possible to complete obviously

#endif

	for (int i = 0; i < 100; i++)
	{
		if (i < size) {
			for (int j = 0; j < 100; j++)
			{
				//Borders of the maze
				if (i == 0 || i == size-1 || j == 0 || j == size-1)
				{
					maze[i][j] = 1;
				}
				//Corners of the maze
				else if ((i == 1 && j == 1) || (i == size - 2 && j == size - 2) || (i == size - 2 && j == 1) || (i == 1 && j == size - 2))
				{
					maze[i][j] = 0;
				}
				else maze[i][j] = 0;
			}
		}
	}
	//Entrence to the maze
	maze[size - 1][size / 2] = 0;



	while (path) {
		pom++;
		maze[x][y] = 2;

		r = rand() % 4;
		std::cout << r;

		switch (r)
		{
			// LEFT
		case 0:
			if (!(dir == 1)) 
			{
				dir = 0;
				std::cout << "LEFT\n";
			}
			

			break;

			// RIGHT
		case 1:
			if (!(dir == 0))
			{
				dir = 1;
				std::cout << "RIGHT\n";

			}

			break;
			// DOWN
		case 2:
			if (!(dir == 3))
			{
				dir = 2;
				std::cout << "DOWN\n";

			}

			break;
			// UP
		case 3:
			if (!(dir == 2))
			{
				dir = 3;
				std::cout << "UP\n";

			}

			break;

		default:

			break;

		}

		if (pom == 20) {
			path = false;
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
				std::cout << " # ";
			}
			else if (maze[i][j] == 0)
			{
				std::cout << "   ";
			}
			else if (maze[i][j] == 2)
			{
				std::cout << " 0 ";
			}
		}
		std::cout << "\n";
	}
}


