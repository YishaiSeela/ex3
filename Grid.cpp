#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "Grid.h"
#include "Node.h"

using namespace std;

Grid::Grid()//int w, int h)
/**
 * Ctor
 */
{
    //int width = w;
    //int height = h;

}

Grid::~Grid()
/**
 * Dtor
 */
{
}

void Grid::setStartAndEnd(Point* startPt, Point* endPt){
    startPt=startPt;
    endPt = endPt;
}

void Grid::destroyGrid()
/**
 * Free all the inner allocated objects
 */
{
    //delete this->startPt;
    //delete this->endPt;

    int i;
    // Delete all the nodes in the grid
    for (i = 0; i < this->gridHeight; i++)
    {
        delete[] this->grid[i];
    }

    delete[] this->grid;
}

bool Grid:: inBoundary(Point p) {
    if (p.getYCoordinate() < 0)
        return false;
    if (p.getXCoordinate() < 0)
        return false;
    if(gridWidth<=p.getXCoordinate())
        return false;
    if(gridHeight<=p.getYCoordinate())
        return false;
    return true;
}
void Grid::createGrid(int gridWidth, int gridHeight)
/**
 * Creates a 2 dimensional grid according to the input
 * of the gridWidth and gridHeight
 */
{
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;
    try {

        // Create one dimensional grid
        this->grid = new Node *[this->gridHeight];

        int u;
        // Create 2D grid
        for (u = 0; u < this->gridHeight; u++) {
            this->grid[u] = new Node[this->gridWidth];
        }

        int i;
        // Initialize each node with default and relevant information
        for (i = 0; i < this->gridHeight; i++)
        {
            int j;
            for (j = 0; j < this->gridWidth; j++)
            {

                // Check if neighbouring nodes exist
                // If the node isn't on the left most colomn
                if (j - 1 >= 0)
                {
                    this->grid[i][j].leftNode = new Point( i, j - 1);
                } else{
                    this->grid[i][j].leftNode = NULL;
                }

                // If the node isn't on the right most colomn
                if (j + 1 < this->gridWidth)
                {
                    this->grid[i][j].rightNode = new Point(i, j + 1);
                } else{
                    this->grid[i][j].rightNode = NULL;
                }

                // If the node isn't on the top most row
                if (i - 1 >= 0)
                {
                    this->grid[i][j].upNode = new Point(i - 1, j);
                } else{
                    this->grid[i][j].upNode = NULL;
                }

                // If the node isn't on the bottom most row
                if (i + 1 < this->gridHeight)
                {
                    this->grid[i][j].downNode = new Point(i + 1, j);
                } else{
                    this->grid[i][j].downNode = NULL;
                }

                // Initialize distance to max value as default
                this->grid[i][j].distance = 0;

                // Initialize coordinates
                this->grid[i][j].coordinate = new Point(i, j);

                // Initialize isVisited flag
                this->grid[i][j].isVisited = false;

                // Initialize parent point
                this->grid[i][j].parentNode = new Point();
            }
        }

    }
    catch (bad_alloc ba)
    {
        cerr << "Bad allocation" << endl;
        exit(EXIT_FAILURE);
    }
}

void Grid::printGrid() {
    for(int i=0;i<gridHeight;i++){
        for(int j=0;j<gridWidth;j++){
            cout<<"("<<grid[i][j].coordinate->getXCoordinate()<<","<<grid[i][j].coordinate->getYCoordinate()<<")";
        }
        cout<<endl;
    }
}

Node* Grid::getNode(int x,int y){
    for(int i=0;i<gridHeight;i++){
        for(int j=0;j<gridWidth;j++){
            if((grid[i][j].coordinate->getXCoordinate()==x)&&(grid[i][j].coordinate->getYCoordinate()==y)){
                return &grid[i][j];
            }
        }
    }
}

Node*Grid::getNode(Point *p){
    return getNode(p->getXCoordinate(),p->getYCoordinate());
}