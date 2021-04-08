#include <iostream>
#include "Puzzle.h"
#include "Node.h"
#include <unordered_set>
#include <stdlib.h>

int main()
{
    int startPuzzle[] = { 1,2,3,4,5,6,7,8,0 };
    int easyPuzzle[] = {4,1,3,7,2,6,0,5,8}; //6 moves
    int mediumPuzzle[] = {7,2,4,5,0,6,8,3,1}; //20 moves
    int difficultPuzzle[] = {6,4,7,8,5,0,3,2,1}; //31 moves
    int crazyPuzzle[] = {8,6,7,2,5,4,3,0,1}; //31 moves

    /*
     * Take a start puzzle and randomize it
    Puzzle p = Puzzle{startPuzzle};
    p.randomize(60);
     */

    Puzzle p = Puzzle(crazyPuzzle);

    std::cout << "Initial puzzle: \n" << p << std::endl;
    p.aStarSolver();

    return 0;
}

