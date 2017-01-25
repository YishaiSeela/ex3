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

#include "Tcp.h"
#include "../SeparateInput/Parser.h"
#include "../Persons/Driver.h"
#include "../TaxiCenter/Ride.h"


using namespace std;
using namespace boost::archive;
std::stringstream ss;

int main(int argc, char *argv[]) {

    string input;
    Driver *driver;
    Vehicle *vehicle;
    Ride *ride;
    Tcp tcp(0,  argv[1] ,atoi(argv[2]));
    tcp.initialize();

    char buffer[100000];


    cin >> input;

    //tcp.sendData(input);

    Parser *prs1;
    prs1 = new Parser();
    prs1->parse(input, 5);
    if (prs1->inputVector.at(0) != "error") {

        int id = atoi(prs1->inputVector.at(0).c_str());
        int age = atoi(prs1->inputVector.at(1).c_str());
        char status = prs1->inputVector.at(2)[0];
        int experiance = atoi(prs1->inputVector.at(3).c_str());
        int vehicleId = atoi(prs1->inputVector.at(4).c_str());

        if ((id >= 0) && (age >= 0) && (experiance >= 0) && (vehicleId >= 0) &&
            ((status == 'M') || (status == 'S') || (status == 'D') || (status == 'W'))) {

            //create driver for serilization
            driver = new Driver(id, age, status, experiance, vehicleId);

            //serialization of driver
            std::string serial_str;
            boost::iostreams::back_insert_device<std::string> inserter(serial_str);
            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
            boost::archive::text_oarchive oa(s);
            oa << driver;
            s.flush();

            sleep(1);
            tcp.sendData(serial_str, 0);
            //recieve vehicle from server
            sleep(1);
            tcp.reciveData(buffer, sizeof(buffer), 0);
            string vehicle_str(buffer, sizeof(buffer));
            boost::iostreams::basic_array_source<char> device(vehicle_str.c_str(), vehicle_str.size());
            boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
            boost::archive::text_iarchive ia(s2);
            ia >> vehicle;

            sleep(1);
            tcp.reciveData(buffer, sizeof(buffer), 0);
            string return_driver_str(buffer, sizeof(buffer));

            while (*buffer != '7') {//!return_driver_str.compare("close")) {
                boost::iostreams::basic_array_source<char> device(return_driver_str.c_str(), return_driver_str.size());
                boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s3(device);
                boost::archive::text_iarchive ia2(s3);
                delete driver;
                ia2 >> driver;
                sleep(1);

                tcp.reciveData(buffer, sizeof(buffer), 0);
                std::string return_ride_str(buffer, sizeof(buffer));
                boost::iostreams::basic_array_source<char> device1(return_ride_str.c_str(), return_ride_str.size());
                boost::iostreams::stream<boost::iostreams::basic_array_source<char> > sRide(device1);
                boost::archive::text_iarchive ir(sRide);
                delete ride;
                ir >> ride;
                sleep(1);

                tcp.reciveData(buffer, sizeof(buffer), 0);

            }
            delete vehicle;
            delete driver;
            delete ride;
            tcp.closeData();
        }
    }
    delete prs1;

    return 0;
}
