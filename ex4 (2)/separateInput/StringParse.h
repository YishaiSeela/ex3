
#ifndef EXERCISE1_STRINGPARSE_H
#define EXERCISE1_STRINGPARSE_H

#include <iostream>
#include <string>
#include "../Map/Grid.h"

class StringParse
// Class parses the input string
{
public:
    void parseInput(Grid &grid, string userInput);
    StringParse();
    ~StringParse();
private:
    //int rideID;
    //int metersPassed;
    //Point startingPoint;
    //Point endingPoint;
    //int numOfPassengers;

};

#endif //EXERCISE1_STRINGPARSE_H
