//
// Created by yanaiela on 12/10/16.
//


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

#include <iostream>
#include "Udp.h"
#include "Parser.h"
#include "Driver.h"
#include <fstream>
#include <sstream>

#include <unistd.h>
#include <stdlib.h>


using namespace std;
using namespace boost::archive;
std::stringstream ss;

int main(int argc, char *argv[]) {

    string input;

    Udp udp(0, atoi(argv[1]));
    udp.initialize();

    char buffer[1024];

    cin >> input;

    udp.sendData(input);
/*
    Parser *prs1;
    prs1 = new Parser();
    prs1->parse(input, 5);
    int id = atoi(prs1->inputVector.at(0).c_str());
    int age = atoi(prs1->inputVector.at(1).c_str());
    char status = prs1->inputVector.at(2)[0];
    int experiance = atoi(prs1->inputVector.at(3).c_str());
    int vehicleId = atoi(prs1->inputVector.at(4).c_str());
    //create driver for serilization
    Driver *driver = new Driver(id, age, status, experiance, vehicleId);
    //serialization
    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::binary_oarchive sendDriver(s);
    sendDriver << driver;
    udp.sendData(serial_str);
    s.flush();

    //save
    text_oarchive oa{ss};
    Driver *ab;
    Driver &rsave = *ab;
    oa << rsave;

    //load
    text_iarchive ia{ss};
    Driver *a;
    Driver &rload = *a;
    ia >> rload;

*/
    std::cout << "pass succeed" << '\n';

    return 0;
}