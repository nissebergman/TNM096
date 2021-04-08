#pragma once
#include <iostream>
#include <vector>


class Puzzle {
public:

    // Constructor
    Puzzle(int _board[9]);
    // Copy constructor
    Puzzle(const Puzzle& p);
    // Randomize a puzzle
    void randomize(int nrOfSteps);
    // Check if the puzzle is correct
    bool verifyPuzzle();
    // h1 - Count tiles that are misplaced
    int h1();
    // h2 - manhattan distance
    int h2();

    //Heuristic function to return f score
    int fvalue(int gscore);

    // Calc possible moves depending on zeroPos
    std::vector<int> possibleMoves();

    //Calculate A* algorithm
    void aStarSolver();

    // Swap the tile
    void swap(int move, Puzzle& p);

    // == operator
    bool operator==(Puzzle& p);
    // overloaded == operator just for unordered set
    bool operator==(const Puzzle& p) const;

    // Ostream operator to print out the puzzle
    friend std::ostream& operator<<(std::ostream& os, const Puzzle &P);

    int board[9];
private:

    int zeroPos;

};

// Hash function for unordered set
class hashFunction
{
public:
    size_t operator()(const Puzzle& p) const
    {
        size_t out{};
        for (int i = 0; i < 9; ++i) {
            out *=10;
            out += p.board[i];
        }
        return out;
    }
};

#include "Node.h"