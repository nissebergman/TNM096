//
// Created by Nisse Bergman on 2021-04-07.
//

#ifndef LAB1WNODE_NODE_H
#define LAB1WNODE_NODE_H
#include "Puzzle.h"


class Node
{
public:

    //Constructor
    Node(int gscore, Puzzle _p) :
            g{ gscore }, p(_p)
    {};

    bool operator<(const Node& n);

    int g{};
    Puzzle p;
};
#endif //LAB1WNODE_NODE_H
