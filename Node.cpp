
#include "Node.h"

Node::Node()
// Ctor with no params
{
    isObstacle = false;
}

Node::Node(Point *initPt)
/**
 * Ctor
 * @param initPt: point with the coordinates of the point
 */
{
    this->coordinate = initPt;
}

Point* Node::getCoordiante()
/*
 * return coordinate of node
 */
{
    return this->coordinate;
}

bool Node::getIsObstacle()
/*
 * return if this node has an obstacle
 */
{
    return isObstacle;
}

void Node::setIsObstacle(bool obstacle)
/*
 * set this node to have an obstacle
 */
{
    isObstacle = obstacle;
}

Node::~Node()
/**
 * Delete all allocated Points in node
 * @param nodeToDelete: The node that needs to be freed
 */
{

    // Delete all the points in the node
    if (this->downNode != NULL)
    {
        delete this->downNode;
    }
    if (this->upNode != NULL)
    {
        delete this->upNode;
    }
    if (this->rightNode != NULL)
    {
        delete this->rightNode;
    }
    if (this->leftNode != NULL)
    {
        delete this->leftNode;
    }
/*
    if (this->parentNode != NULL)
    {
        delete this->parentNode;
    }
*/
    // Free the coordinate
    delete this->coordinate;

}