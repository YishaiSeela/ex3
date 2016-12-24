
#include <iostream>
#include "Point.h"

using namespace std;

Point::Point()
/**
 * Ctor
 */
{
}

Point::Point(int x, int y)
/**
 * Initializes the coordinates
 * @param x: X coordinate of the point
 * @param y: Y coordinate of the point
 */
{
    this->x = x;
    this->y = y;
}

ostream &operator<<(ostream outStream, Point &pt)
/**
 * Overload the << operator to print in (x,y)
 * @param outStream: Stream to priint
 * @param pt: The point to print
 */
{
    outStream << "(" << pt.getXCoordinate() <<
              "," << pt.getYCoordinate() << ")";
}

int Point::getXCoordinate()
/**
 * Getter of the x coordinate of the point
 * @return: The coordinate of x
 */
{
    return this->x;
}

int Point::getYCoordinate()
/**
 * Getter of the y coordinate of the point
 * @return: The coordinate of y
 */
{
    return this->y;
}

bool Point::operator==(Point &otherPt)
/**
 * Overload the "==" operator to check that x and
 * y coordinates are equal
 * @param otherPt: The other point to compare
 * @return: True if the points are equal otherwise false
 */
{

    // If the points are equal
    return (this->getXCoordinate() == otherPt.getXCoordinate()
            && this->getYCoordinate() == otherPt.getYCoordinate());
}

bool Point::operator!=(Point &otherPt)
/**
 * Overload "!=" operator to check if the x and y
 * coordinates are not equal
 * @param otherPt: The other point to compare
 * @return: True if the points are not equal otherwise false
 */
{
    return (this->getXCoordinate() != otherPt.getXCoordinate()
            || this->getYCoordinate() != otherPt.getYCoordinate());
}

ostream &operator<<(ostream &outStream, Point &pt)
/**
 * Overload stream to print the coordinates of the point in brackets
 * @param outStream: The output stream
 * @param pt: The point that should be print
 * @return: The stream in the format "(x,y)"
 */
{
    return outStream << "(" << pt.getXCoordinate()
                     << "," << pt.getYCoordinate() << ")";
}