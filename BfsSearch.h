
#ifndef EXERCISE1_BFSSEARCH_H
#define EXERCISE1_BFSSEARCH_H


#include "Grid.h"
#include <queue>

class BfsSearch
// Class that performs the bfs algorithm search
// and prints the shortest path
{

public:
    queue<Node *> ptQueue; // The stack for the bfs algorithm
    Grid gameGrid; // The grid of the map
    //BfsSearch(Grid &grid); // Ctor
    BfsSearch(Grid *grid); // Ctor
    void runBfs(); // Run the algorithm
    void visitNode(Node* parent, Node *vistingNode);
    void printPath(); // Prints the shortest path




};


#endif //EXERCISE1_BFSSEARCH_H