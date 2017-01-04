#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
#include "Grid.h"
#include "Node.h"

using namespace std;

Grid::Grid()
/**
 * Ctor
 */
{


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
        this->grid = new Node *[this->gridHeight];

        // Create one dimensional grid
        this->grid = new Node *[this->gridHeight];

        int u;
        // Create 2D grid
        for (u = 0; u < this->gridHeight; u++) {

            this->grid[u] = new Node[this->gridWidth];
        }

        for(int i=0;i<gridHeight;i++){
            for(int j=0;j<gridWidth;j++){
                // Initialize distance to max value as default
                this->grid[i][j].distance = 0;

                // Initialize coordinates
                this->grid[i][j].coordinate = new Point(gridHeight-i-1, j);

                // Initialize isVisited flag
                this->grid[i][j].isVisited = false;

            }
        }

        // Initialize each node with default and relevant information
        for (int i = 0; i<gridHeight ; i++)
        {
            for (int j = 0; j <gridWidth; j++)
            {

                // Check if neighbouring nodes exist
                // If the node isn't on the left most colomn
                if (0<this->grid[i][j].coordinate->getYCoordinate())
                {
                    this->grid[i][j].leftNode = getNode(this->grid[i][j-1].coordinate)->coordinate;
                } else{
                    this->grid[i][j].leftNode = NULL;
                }

                // If the node isn't on the right most colomn
                if (this->grid[i][j].coordinate->getYCoordinate()<gridWidth-1)
                {
                    this->grid[i][j].rightNode = getNode(this->grid[i][j+1].coordinate)->coordinate;
                } else{
                    this->grid[i][j].rightNode = NULL;
                }

                // If the node isn't on the bottom most row
                if (0<this->grid[i][j].coordinate->getXCoordinate())
                {
                    this->grid[i][j].downNode = getNode(this->grid[i+1][j].coordinate)->coordinate;
                } else{
                    this->grid[i][j].downNode = NULL;
                }

                // If the node isn't on the top most row
                if (this->grid[i][j].coordinate->getXCoordinate()<gridHeight-1)
                {
                    this->grid[i][j].upNode = getNode(this->grid[i-1][j].coordinate)->coordinate;
                } else{
                    this->grid[i][j].upNode = NULL;
                }


            }
        }

    }
    catch (bad_alloc ba)
    {
        cerr << "Bad allocation" << endl;
        exit(EXIT_FAILURE);
    }
}

void Grid::setObstacle(Point p) {
    this->grid[p.getXCoordinate()][p.getYCoordinate()].setIsObstacle(true);
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
