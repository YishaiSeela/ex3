#include <iostream>
#include <fstream>
#include <sstream>
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

#include "Udp.h"
#include "Parser.h"
#include "Driver.h"
#include "Ride.h"


using namespace std;
using namespace boost::archive;
std::stringstream ss;

int main(int argc, char *argv[]) {

    string input;
    Driver *driver;
    Vehicle *vehicle;
    Ride *ride;
    Udp udp(0,  argv[1] ,atoi(argv[2]));
    udp.initialize();

    char buffer[1024];


    cin >> input;

    //udp.sendData(input);

    Parser *prs1;
    prs1 = new Parser();
    prs1->parse(input, 5);
    int id = atoi(prs1->inputVector.at(0).c_str());
    int age = atoi(prs1->inputVector.at(1).c_str());
    char status = prs1->inputVector.at(2)[0];
    int experiance = atoi(prs1->inputVector.at(3).c_str());
    int vehicleId = atoi(prs1->inputVector.at(4).c_str());
    //create driver for serilization
    driver = new Driver(id, age, status, experiance, vehicleId);

    //serialization of driver
    std::string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
    boost::archive::text_oarchive oa(s);
    oa << driver;
    s.flush();

    udp.sendData(serial_str);
    //recieve vehicle from server
    udp.reciveData(buffer, sizeof(buffer));
    string vehicle_str(buffer, sizeof(buffer));
    boost::iostreams::basic_array_source<char> device(vehicle_str.c_str(), vehicle_str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::text_iarchive ia(s2);
    ia >> vehicle;

    //recieve ride from server
    udp.reciveData(buffer, sizeof(buffer));
    std::string ride_str(buffer, sizeof(buffer));
    boost::iostreams::basic_array_source<char> device1(ride_str.c_str(), ride_str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > sRide(device1);
    boost::archive::text_iarchive ir(sRide);
    ir >> ride;


    udp.reciveData(buffer, sizeof(buffer));
    string return_driver_str(buffer, sizeof(buffer));

    while (*buffer != '7'){//!return_driver_str.compare("close")) {
    boost::iostreams::basic_array_source<char> device(return_driver_str.c_str(), return_driver_str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device);
    boost::archive::text_iarchive ia2(s3);
    delete driver;
    ia2 >> driver;

    udp.reciveData(buffer, sizeof(buffer));

}
    delete vehicle;
    delete driver;
    delete ride;
    delete prs1;
    udp.closeData();

    return 0;
}