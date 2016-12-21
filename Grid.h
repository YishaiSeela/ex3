
#ifndef EXERCISE1_GRID_H
#define EXERCISE1_GRID_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "Grid.h"
#include "Node.h"
#include "Point.h"

using namespace std;

class Grid
// The grid that holds a matrix of Nodes
{

public:
    Grid();//int w, int h);
    ~Grid();
    void destroyGrid();
    int gridWidth, gridHeight; // Height and width of the grid
    Point *startPt; // Starting point
    Point *endPt; // Ending point
    Node **grid; // Matrix of the grid
    void createGrid(int gridWidth, int gridHeight);// Initialize the grid
    void setStartAndEnd(Point* startPt, Point* endPt);
    void dummyConstructor(int width, int height);
    bool inBoundary(Point p);

};


#endif //EXERCISE1_GRID_H
