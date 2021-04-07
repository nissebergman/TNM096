#include <iostream>
#include "Puzzle.h"
#include "Node.h"
#include <unordered_set>

int main()
{
    int easyPuzzle[] = {4,1,3,7,2,6,0,5,8}; //6 moves
    int mediumPuzzle[] = {7,2,4,5,0,6,8,3,1}; //20 moves
    int difficultPuzzle[] = {6,4,7,8,5,0,3,2,1}; //31 moves
    int crazyPuzzle[] = {8,6,7,2,5,4,3,0,1}; //31 moves
    int puzzle[] = { 2,5,0,1,4,8,7,3,6 };
    //Create puzzle with custom input, g = 0
    Puzzle p = Puzzle(crazyPuzzle);

    std::cout << "Start puzzle: \n" << p << std::endl;

    p.aStarSolver();

    return 0;
}

