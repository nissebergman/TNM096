#pragma once
#include <iostream>
#include <vector>
class Puzzle {
public:


    // Constructor
    Puzzle(int _board[9]);
    // Copy constructor
    Puzzle(const Puzzle& p);
    // Check if the puzzle is correct
    bool verifyPuzzle();
    // h1 - Count tiles that are misplaced
    int h1();
    // h2 - manhattan distance


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

    // Ostream operator to print out the puzzle
    friend std::ostream& operator<<(std::ostream& os, const Puzzle &P);

private:
    int board[9];
    int zeroPos;



};
class Node
{
public:

    //Constructor
    Node(int gscore, Puzzle _p) :
            g{ gscore }, p(_p)
    {};


    int g{};
    Puzzle p;
};