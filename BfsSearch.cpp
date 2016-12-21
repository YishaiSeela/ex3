
#include <iostream>
#include "BfsSearch.h"

using namespace std;

BfsSearch::BfsSearch(Grid *grid)
/**
 * Ctor
 * @param grid: The grid to run the algorithm on
 */
{
    this->gameGrid = *grid;
}

void BfsSearch::calculatePath()
/**
 * Calculates the distance from the end point to the start point
 */
{

    // Marks starting point as visited
    this->gameGrid.grid
    [this->gameGrid.endPt->getXCoordinate()]
    [this->gameGrid.endPt->getYCoordinate()].isVisited = true;

    // Push the ending point into the queue
    this->ptQueue.push(&(this->gameGrid.grid
    [this->gameGrid.endPt->getXCoordinate()]
    [this->gameGrid.endPt->getYCoordinate()]));

    // Run the algorithm as long as queue is not empty
    // or the destination has been calculated
    while (!this->ptQueue.empty())
    {

        // pop the node from the queue
        Node *tempNode = this->ptQueue.front();
        this->ptQueue.pop();

        // If up node is in grid
        if (tempNode->upNode != NULL) {

            Node *upNode = &(this->gameGrid.grid
            [tempNode->upNode->getXCoordinate()]
            [tempNode->upNode->getYCoordinate()]);

            // Check if the up node has default distance
            if (!upNode->isVisited) {

                // Update distance and push to queue
                upNode->distance = tempNode->distance + 1;
                upNode->isVisited = true;
                *upNode->parentNode = *tempNode->coordinate;
                this->ptQueue.push(upNode);
            }
        }

        // If right node is in grid
        if (tempNode->rightNode != NULL) {

            Node *rightNode = &(this->gameGrid.grid
            [tempNode->rightNode->getXCoordinate()]
            [tempNode->rightNode->getYCoordinate()]);

            // Check if the right node has default distance
            if (!rightNode->isVisited) {

                // Update distance and push to queue
                rightNode->distance = tempNode->distance + 1;
                rightNode->isVisited = true;
                *rightNode->parentNode = *tempNode->coordinate;
                this->ptQueue.push(rightNode);
            }
        }

        // If down node is in grid
        if (tempNode->downNode != NULL) {

            Node *downNode = &(this->gameGrid.grid
            [tempNode->downNode->getXCoordinate()]
            [tempNode->downNode->getYCoordinate()]);

            // Check if the down node has default distance
            if (!downNode->isVisited) {

                // Update distance and push to queue
                downNode->distance = tempNode->distance + 1;
                downNode->isVisited = true;
                *downNode->parentNode = *tempNode->coordinate;
                this->ptQueue.push(downNode);
            }
        }

        // Check all the adjacent nodes
        // If left node is in grid
        if (tempNode->leftNode != NULL) {

            Node *leftNode = &(this->gameGrid.grid
            [tempNode->leftNode->getXCoordinate()]
            [tempNode->leftNode->getYCoordinate()]);

            // Check if the left node has default distance
            if (!leftNode->isVisited) {

                // Update distance and push to queue
                leftNode->distance = tempNode->distance + 1;
                leftNode->isVisited = true;
                *leftNode->parentNode = *tempNode->coordinate;
                this->ptQueue.push(leftNode);
            }
        }
    }
}

void BfsSearch::printPath()
/**
 * Prints the shortest path from start point to end point
 */
{

    // Set the currNode to start from the end point
    Node *currNode = &(this->gameGrid.grid
    [this->gameGrid.startPt->getXCoordinate()]
    [this->gameGrid.startPt->getYCoordinate()]);

    // Print the coordinates until the start point is reached
    while(*(currNode->coordinate) != *(this->gameGrid.endPt))
    {
        cout << *(currNode->coordinate);

        // Update current node to parent node
        currNode = &(this->gameGrid.grid
        [(*currNode).parentNode->getXCoordinate()]
        [(*currNode).parentNode->getYCoordinate()]);
    }

    cout << *(currNode->coordinate);

}


std::vector<Node*> BfsSearch::getPath()
/**
 * Prints the shortest path from start point to end point
 */
{

    // Set the currNode to start from the end point
    std::vector<Node*> path;
    Node *currNode = &(this->gameGrid.grid
    [this->gameGrid.startPt->getXCoordinate()]
    [this->gameGrid.startPt->getYCoordinate()]);

    // Print the coordinates until the start point is reached
    while(*(currNode->coordinate) != *(this->gameGrid.endPt))
    {
        path.push_back(currNode);

        // Update current node to parent node
        currNode = &(this->gameGrid.grid
        [(*currNode).parentNode->getXCoordinate()]
        [(*currNode).parentNode->getYCoordinate()]);
    }

    return path;

}


void BfsSearch::runBfs()
/**
 * Runs the bfs algorithm and prints the shortest path
 */
{
    this->calculatePath();

    this->printPath();
}