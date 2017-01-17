
#include <iostream>
#include <sstream>
#include <string>
#include "../Map/Grid.h"
#include "StringParse.h"

using namespace std;
StringParse::StringParse()
{
}

StringParse::~StringParse()
{
}

void StringParse::parseInput(Grid &grid, string userInput)
/**
 * Parses the string the user input into three members of the class
 * @param grid: The grid that will be initialized
 * @param userInput: The input of the user
 */
{

    string underScoreSeperator = "_";
    char commaSeperator = ',';
    int numOfParamsInputByUser = 3; // Number of params given by the user

    // Array of strings with params given by the user
    string inputParams[numOfParamsInputByUser];

    int i;
    // Seperate the grid size, start point and end point into inputParams array
    for (i = 0; i < numOfParamsInputByUser; i++)
    {
        inputParams[i] = userInput.substr(0, userInput.find(commaSeperator));
        userInput.replace(0, inputParams[i].length() + 1, "");
    }

    // The string with grid size
    string gridSize = inputParams[0] + commaSeperator;
    // The string with start point
    string startPoint = inputParams[1] + commaSeperator;
    // The string with end point
    string endPoint = inputParams[2] + commaSeperator;

    unsigned long positionOfSeperatorGrid = gridSize.find(underScoreSeperator);
    unsigned long positionOfSeperatorStartPt = startPoint.find
            (underScoreSeperator);
    unsigned long positionOfSeperatorEndPt = endPoint.find
            (underScoreSeperator);


    // Turn string to int with stream
    istringstream tempWidthStream(gridSize.substr(0, positionOfSeperatorGrid));
    tempWidthStream >> grid.gridWidth;
    grid.gridWidth += 1;

    // Turn string to int with stream
    istringstream tempHeightStream(gridSize.substr
            (positionOfSeperatorGrid + 1, (unsigned long)
                    gridSize.find_last_of(commaSeperator)));

    tempHeightStream >> grid.gridHeight;
    grid.gridHeight += 1;

    try
    {
        // Turn string to int with stream
        istringstream tempXStartPtStream(startPoint.substr
                (0, positionOfSeperatorStartPt));

        // Turn string to int with stream
        istringstream tempYStartPtStream(startPoint.substr
                (positionOfSeperatorStartPt + 1,
                 (unsigned long) gridSize.find_last_of(commaSeperator)));

        int xPt, yPt;
        tempXStartPtStream >> xPt;
        tempYStartPtStream >> yPt;

        // Init start point with point
        grid.startPt = new Point(xPt, yPt);

        // Turn string to int with stream
        istringstream tempXEndPtStream(endPoint.substr
                (0, positionOfSeperatorEndPt));

        // Turn string to int with stream
        istringstream tempYEndPtStream(endPoint.substr
                (positionOfSeperatorEndPt + 1,
                 (unsigned long) gridSize.find_last_of(commaSeperator)));

        tempXEndPtStream >> xPt;
        tempYEndPtStream >> yPt;

        // Initialize end point with point
        grid.endPt = new Point(xPt, yPt);

    }
        // If memory allocation fails
    catch (bad_alloc ba)
    {
        cerr << "Bad alloc" << endl;
        exit(EXIT_FAILURE);
    }
}
