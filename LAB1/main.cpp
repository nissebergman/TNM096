#include <iostream>
#include "Puzzle.h"

int main()
{
    int puzzle[] = {2,5,0,1,4,8,7,3,6};

    //Create puzzle with custom input, g = 0
    Puzzle p = Puzzle(puzzle);

    std::cout << "Start puzzle: \n" << p << std::endl;
    p.aStarSolver();

    //std::cout << "Number of misplaced tiles " << p.h1() << std::endl;

    return 0;
}

