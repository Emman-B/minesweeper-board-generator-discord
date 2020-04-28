#ifndef MINESWEEPER_DECLARATIONS_HPP
#define MINESWEEPER_DECLARATIONS_HPP

namespace minesweeper
{
    namespace cell_type
    {
        constexpr uint8_t BLANK = 0, 
            ONE = 1,
            TWO = 2,
            THREE = 3,
            FOUR = 4,
            FIVE = 5,
            SIX = 6,
            SEVEN = 7,
            EIGHT = 8,
            MINE = 9; 
    }

    const std::vector<std::pair<const size_t, const size_t>> adjacency_deltas
    {
        // top
        {-1, -1}, // left
        {-1, 0}, // mid
        {-1, 1}, // right

        // mid
        {0, -1}, // left
        {0, 1},  // right

        // bot
        {1, -1}, // left
        {1, 0}, // mid
        {1, 1}, // right
    };

    std::unordered_map<uint8_t, std::string> conversion_map
    {
        {cell_type::BLANK, "blue_square"},
        {cell_type::ONE, "one"},
        {cell_type::TWO, "two"},
        {cell_type::THREE, "three"},
        {cell_type::FOUR, "four"},
        {cell_type::FIVE, "five"},
        {cell_type::SIX, "six"},
        {cell_type::SEVEN, "seven"},
        {cell_type::EIGHT, "eight"},
        {cell_type::MINE, "x"}
    };
}
#endif