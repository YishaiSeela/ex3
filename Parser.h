//
// Created by yishai on 12/13/16.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H


#include <list>

class Parser {
public:
    Parser();
    //string inputParams[get id(),get age()];

    std::vector<std::string> parse(string userInput, int params);
    std::list <string> listOfParams;
    std::vector<std::string> inputVector;
    string inputParams[10];
    string getInput(int i);
    ~Parser();

};


#endif //EX2_PARSER_H


