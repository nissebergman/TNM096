#include <iostream>
#include "Puzzle.h"
#include "Node.h"

int main()
{
    int easyPuzzle[] = {4,1,3,7,2,6,0,5,8}; //6 moves
    int mediumPuzzle[] = {7,2,4,5,0,6,8,3,1}; //20 moves
    int difficultPuzzle[] = {6,4,7,8,5,0,3,2,1}; //31 moves
    int crazyPuzzle[] = {8,6,7,2,5,4,3,0,1}; //31 moves

    //Create puzzle with custom input, g = 0
    Puzzle p = Puzzle(mediumPuzzle);

    std::cout << "Start puzzle: \n" << p << std::endl;
    p.aStarSolver();

    //std::cout << "Number of misplaced tiles " << p.h1() << std::endl;

    return 0;
}

