#include "Puzzle.h"
#include <algorithm>

Puzzle::Puzzle(int _board[9])
        :zeroPos{0}
{

    for (size_t i = 0; i < 9; i++)
    {
        board[i] = _board[i];
        if (board[i] == 0)
            zeroPos = i;
    }
}

Puzzle::Puzzle(const Puzzle& p)
{
    zeroPos = p.zeroPos;
    for (int i = 0; i < 9; i++){
        board[i] = p.board[i];
    }
}

bool Puzzle::verifyPuzzle()
{
    for (size_t i = 0; i < 9; i++)
    {
        if ((board[i] != i + 1) && board[i] != 0)
            return false;
    }
    return true;
}

int Puzzle::h1()
{
    int counter{};
    for (int i = 0; i < 9; i++){
        int tileValue = board[i];
        if (tileValue != i+1 && tileValue != 0)
            counter++;
    }
    return counter;
}

bool sortOpenList(Node n1, Node n2){
    return (n1.p.fvalue(n1.g) < n2.p.fvalue(n2.g));
}

void Puzzle::aStarSolver()
{
    std::vector<Node> closedList;
    std::vector<Node> openList;
    std::vector<int> possibleMoves;


    Node root(0, *this);
    openList.push_back(root);
    while (!openList.empty())
    {
        Node currentNode = openList.front();
        Puzzle currentPuzzle = openList.front().p;

        closedList.push_back(openList.front());
        openList.erase(openList.begin());

        // Check if puzzle is solved
        if(currentPuzzle.verifyPuzzle())
        {
            std::cout << "Operation is done at g = " << currentNode.g << std::endl;
            std::cout << currentNode.p << std::endl;
            break;
        }


        possibleMoves = currentPuzzle.possibleMoves();


        for (int i = 0; i < possibleMoves.size(); i++)
        {
            Node newNode = Node(currentNode.g + 1, currentNode.p);
            newNode.p.swap(possibleMoves[i], newNode.p);
            //std::swap(newNode.p.board[zeroPos], newNode.p.board[possibleMoves[i]]);
            zeroPos = possibleMoves[i];
            bool isInClosedList = false;
            for (size_t j = 0; j < closedList.size(); j++)
            {
                if (newNode.p == closedList[j].p)
                {
                    isInClosedList = true;
                    break;
                }
            }
            if(!isInClosedList)
            {
                openList.push_back(newNode);
            }
        }


        //Sort openList
        std::sort(openList.begin(), openList.end(), sortOpenList);


        std::cout << "Step " << std::endl;
        std::cout << openList.front().p << std::endl << std::endl;
    }

}


void Puzzle::swap(int move, Puzzle& p)
{
    std::swap(p.board[zeroPos], p.board[move]);
    zeroPos = move;
}

int Puzzle::fvalue(int gscore)
{
    int hscore1 = h1();
    //int hscore2 = h2();
    return gscore + hscore1;
}

std::vector<int> Puzzle::possibleMoves()
{
    std::vector<int> moves;
    switch(zeroPos)
    {
        case 0:
            moves = {1, 3};
            break;
        case 1:
            moves = {0, 2, 4};
            break;
        case 2:
            moves = {1, 5};
            break;
        case 3:
            moves = {4, 0, 6};
            break;
        case 4:
            moves = {3, 1, 7, 5};
            break;
        case 5:
            moves = {4, 2, 8};
            break;
        case 6:
            moves = {7, 3};
            break;
        case 7:
            moves = {6, 8, 4};
            break;
        case 8:
            moves = {7, 5};
            break;

        default:
            break;
    }
    return moves;
}

bool Puzzle::operator==(Puzzle& p)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != p.board[i])
        {
            return false;
        }
    }
    return true;
}




std::ostream& operator<<(std::ostream& os, const Puzzle& P)
{
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            os << P.board[row*3+column];
            os << "  ";
        }
        os << "\n";
    }
    return os;
}


//1 2 3
//4 5 6
//7 8 0
