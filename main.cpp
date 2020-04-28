
#include <iostream>
#include <fstream>

#include <string>

#include <vector>
#include <unordered_map>

#include <random>



#include "minesweeper_declarations.hpp"
    // namespace minesweeper, cell_type, adjacency_deltas, conversion_map

int main(int argc, char** argv)
{
    using namespace minesweeper;

	std::random_device rd{};
	std::mt19937 engine(rd());
    
	constexpr size_t width  = 10;
	constexpr size_t height = 10;
	constexpr size_t num_mines = 10;

	static_assert(num_mines < width * height, "");

	std::ofstream outputfile("minesweeper.txt");
	outputfile << "Minesweeper!" << std::endl;

	// initialize board
	std::vector<std::vector<uint8_t>> board{};
	for (size_t row = 0; row < width; row++)
	{
		board.push_back(std::vector<uint8_t>());
		for (size_t col = 0; col < height; col++)
		{
			board.back().push_back(cell_type::BLANK);
		}
	}

	// track mines with vector of pairs
	std::vector<std::pair<size_t, size_t>> mine_locations{};

	// place mines randomly
	size_t current_num_mines = 0;
	while (current_num_mines < num_mines)
	{
		size_t rng_row = engine() % 10;
		size_t rng_col = engine() % 10;
		auto& check = board[rng_row][rng_col];
		if (check == cell_type::BLANK)
		{
			check = cell_type::MINE;
			mine_locations.push_back({ rng_row, rng_col });
		}
		else
		{
			continue;
		}
		current_num_mines++;
	}

	// now go through mine_locations and mark adjacent numbers
	for (auto position : mine_locations)
	{
		size_t row = position.first;
		size_t col = position.second;

		// check adjacency
		for (auto delta : adjacency_deltas)
		{
			size_t new_row = row + delta.first;
			size_t new_col = col + delta.second;
			if (new_row >= 0 && new_row < height)
			{
				if (new_col >= 0 && new_col < width)
				{
					if (board[new_row][new_col] != cell_type::MINE)
					{
						board[new_row][new_col] = board[new_row][new_col] + 1;
					}
				}
			}
		}
	}

	// print minesweeper board to console
	for (auto row : board)
	{
		for (auto cell : row)
		{
			std::cout << static_cast<int>(cell);
		}
		std::cout << std::endl;
	}
	
	// write it (in discord style) to outputfile
	for (auto row : board)
	{
		for (auto cell : row)
		{
			auto current_cell_iter = conversion_map.find(cell);
			if (current_cell_iter != conversion_map.end())
			{
				outputfile << "||:" << current_cell_iter->second << ":||";
			}
		}
		outputfile << std::endl;
	}
	outputfile.close();
}