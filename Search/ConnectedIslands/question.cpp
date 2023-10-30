#include <iostream>
#include <vector>

/**
    1- the given 2d grid is binary (0 or 1), but you can modifiy it if needed
    2- for each cell, we consider its 4-directions (top, bottom, left and right) to find a potential connected component.
    3- a connected component can't expand out of the grid (opposite) boundaries.
*/

std::vector<std::vector<std::size_t>> gridmap
    {{1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 1, 1}};

std::size_t computeNumIslands(std::vector<std::vector<std::size_t>>& grid) 
{
    // TODO
    return 0;
}

int main() 
{
    const std::size_t noIslands = computeNumIslands(gridmap);

    std::cout << "No. of islands is " << noIslands << '\n';

    return 0;
}
