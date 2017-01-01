//
// Created by yishai on 12/13/16.
//

#ifndef EX3_PARSER_H
#define EX3_PARSER_H


#include <list>
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

class Parser {
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & parse;
        ar & listOfParams;
        ar & inputVector;
        ar & inputParams;
    }

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


