#ifndef LAB1WNODE_NODE_H
#define LAB1WNODE_NODE_H



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
