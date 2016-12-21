
#ifndef EXERCISE1_NODE_H
#define EXERCISE1_NODE_H

#include "Point.h"

class Node
// Node that holds the coordinates of all the adjacent
// nodes.
{
public:
    Point *leftNode; // Left node of the point
    Point *upNode; // Up node of the point
    Point *downNode; // Down node of the point
    Point *rightNode; // Right node of the point
    Point *parentNode; // Parent node of the point
    int distance; // Distance from the end point
    bool isVisited;
    bool isObstacle;
    Point *coordinate;
    Node(); // Ctor
    Node(Point *initPt); // Ctor
    ~Node(); // Dtor

    Point* getCoordiante();
    bool getIsObstacle();
    void setIsObstacle(bool);

};

#endif //EXERCISE1_NODE_H
