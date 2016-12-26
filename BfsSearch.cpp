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

void BfsSearch::visitNode(Node* parent, Node *vistingNode){
    // Check if the down node has default distance
    if (!vistingNode->isVisited) {

        // Update distance and push to queue
        vistingNode->distance = parent->distance + 1;
        vistingNode->isVisited = true;
        vistingNode->parentNode = (Point *) parent;
        this->ptQueue.push(vistingNode);
    }
}

void BfsSearch::runBfs()
/**
 * Calculates the distance from the end point to the start point
 */
{

    // Marks start point as visited
    //check if null
    int x = this->gameGrid.startPt->getXCoordinate();
    int y = this->gameGrid.startPt->getYCoordinate();

    this->gameGrid.getNode(x,y)->isVisited = true;

    // Push the ending point into the queue
    this->ptQueue.push(gameGrid.getNode(x,y));

    // Run the algorithm as long as queue is not empty
    // or the destination has been calculated
    while (!this->ptQueue.empty())
    {

        // pop the node from the queue
        Node *tempNode = this->ptQueue.front();

        //cout << "("<<tempNode->coordinate->getXCoordinate() << "," << tempNode->coordinate->getYCoordinate() << ")"<<endl;

        this->ptQueue.pop();
        if(tempNode!=NULL) {

            // Check all the adjacent nodes
            // If left node is in grid

            if (tempNode->downNode != NULL) {
                visitNode(tempNode,gameGrid.getNode(tempNode->downNode));
            }
            if (tempNode->rightNode != NULL) {
                visitNode(tempNode,gameGrid.getNode(tempNode->rightNode));
            }
            if (tempNode->upNode != NULL) {
                visitNode(tempNode,gameGrid.getNode(tempNode->upNode));
            }
            if (tempNode->leftNode != NULL) {
                visitNode(tempNode,gameGrid.getNode(tempNode->leftNode));
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

    Node *current = gameGrid.getNode(gameGrid.endPt);
    Node *start = gameGrid.getNode(gameGrid.startPt);
    // Print the coordinates until the start point is reached
    while(current!=start)
    {
        Node *temp= (Node *) current->parentNode;
        temp->sonNode=current;
        current=temp;
    }
    current=start;
    Node *end = gameGrid.getNode(gameGrid.endPt);
    while(current!=end){
        cout << *(current->coordinate)<<endl;
        current=current->sonNode;
    }
    cout << *(current->coordinate);

}