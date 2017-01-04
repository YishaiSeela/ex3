
#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <vector>
#include "Grid.h"
#include "StringParse.h"

using namespace std;

//
// Created by yishai on 12/13/16.
//

#include "Parser.h"

Parser::Parser()
/*
 * ctor
 */
{
}

std::vector <std::string> Parser::parse(string userInput, int params)
/*
 * create vector of inputs
 */
{

    char commaSeperator = ',';
    int numOfParamsInputByUser = params; // Number of params given by the user

    // Array of strings with params given by the user
    string inputParams[numOfParamsInputByUser];

    int i;
    // Separate the different inputs and save them in a vector
    for (i = 0; i < numOfParamsInputByUser; i++) {
        inputParams[i] = userInput.substr(0, userInput.find(commaSeperator));
        userInput.replace(0, inputParams[i].length() + 1, "");
        inputVector.push_back(inputParams[i]);
    }

    return inputVector;
}

Parser::~Parser()
/*
 * dtor
 */
{
}

