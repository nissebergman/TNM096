#include <iostream>
#include "Puzzle.h"
#include "Node.h"
#include <unordered_set>
#include <stdlib.h>
#include <chrono>

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

    // Create start and end time points using system clock through chrono
    std::chrono::time_point<std::chrono::system_clock> start, stop;

    // Start counting execution time
    start = std::chrono::system_clock::now();
    // Start solving
    p.aStarSolver();
    // Stop counting execution time
    stop = std::chrono::system_clock::now();
    // Get elapsed time between start and stop
    std::chrono::duration<double> totalTime = stop - start;
    std::cout << "Solved puzzle in: " << totalTime.count() << " seconds";
    return 0;
}

