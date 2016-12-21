
#ifndef EXERCISE1_POINT_H
#define EXERCISE1_POINT_H

#include <iostream>

using namespace std;

class Point
// Class of a point
// Consists of x and y coordinates
{

public:
    Point ();
    int x; // X coordinate
    int y; // Y coordinate
    Point(int x, int y); // Constructor
    int getXCoordinate(); // X coordinate getter
    int getYCoordinate(); // Y coordinate getter
    bool operator==(const Point &otherPt) const;
    bool operator!=(Point &otherPt);
    float distance(Point);


protected:


friend ostream &operator<<(ostream &outStream, Point &pt); // Operator overload

};

#endif //EXERCISE1_POINT_H
