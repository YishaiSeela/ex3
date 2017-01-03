
#ifndef EXERCISE1_NODE_H
#define EXERCISE1_NODE_H
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
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
    Node *sonNode; // Parent node of the point
    int distance; // Distance from the end point
    bool isVisited;
    bool isObstacle;
    Point *coordinate;
    string toString();
    Node(); // Ctor
    Node(Point *initPt); // Ctor
    ~Node(); // Dtor

    Point* getCoordiante();
    bool getIsObstacle();
    void setIsObstacle(bool);

};

#endif //EXERCISE1_NODE_H