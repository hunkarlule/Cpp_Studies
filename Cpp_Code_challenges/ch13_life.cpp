// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main() {

	// The game, initialized with a glider and a blinker.
	char game[N][M];
	std::memset(game, '-', N * M); // Initialize game with dashes.

	// A glider     // - - - - - - - - - -
	game[1][1] = 'X'; // - X - - - - - - - -
	game[2][2] = 'X'; // - - X - - - - - - -
	game[3][0] = 'X'; // X X X - - - - - - -
	game[3][1] = 'X';
	game[3][2] = 'X';

	// A blinker    // - - - - - - - - - -
	game[3][6] = 'X'; // - - - - - - - - - -
	game[3][7] = 'X'; // - - - - - - - - - -
	game[3][8] = 'X'; // - - - - - - X X X -

	int generation = 0;
	std::string go_on;
	do {
		std::cout << "Generation #" << generation++ << "\n";

		for (auto& str : game) {
			for (auto& ch : str)
				std::cout << " " << ch;
			std::cout << "\n";
		}
		std::cout << "\n";

		// Write your code here

		char gameInNextGen[N][M];
		std::memset(gameInNextGen, '-', N * M); // Initialize gameinNextGen with dashes.
		int neighboorCells[8][2] = { {1, 1},{1, 0},{1, -1}, {0, 1},{0, -1}, {-1, 1},{-1, 0},{-1, -1} };
		int liveNeighboorCount = 0;


		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {

				liveNeighboorCount = 0;
				for (int i = 0; i < 8; i++) {
					auto& neighboor = neighboorCells[i];
					auto neighboorRowStep = neighboor[0];
					auto neighboorColStep = neighboor[1];
					auto tempRow = (row + neighboorRowStep) % N;
					auto neighboorRow = tempRow < 0 ? tempRow + N : tempRow;
					auto tempCol = (col + neighboorColStep) % M;
					auto neighboorCol = tempCol < 0 ? tempCol + M : tempCol;

					if (game[neighboorRow][neighboorCol] == 'X') {
						liveNeighboorCount++;
					}
				}

				if (game[row][col] == '-') {
					if (liveNeighboorCount == 3) {
						gameInNextGen[row][col] = 'X';
					}
				}

				if (game[row][col] == 'X') {
					if (liveNeighboorCount == 3 || liveNeighboorCount == 2) {
						gameInNextGen[row][col] = 'X';
					}
				}
			}
		}


		for (size_t row = 0; row < N; row++) {
			for (size_t col = 0; col < M; col++) {
				game[row][col] = gameInNextGen[row][col];
			}
		}

		std::cout << "\n";
		std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
		std::getline(std::cin, go_on);
		std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
		std::cout << "\n" << std::flush;
	} while (go_on.compare("EXIT") != 0);

	return 0;
}
