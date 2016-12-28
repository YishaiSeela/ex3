////
//// Created by yanaiela on 12/10/16.
////
//#include "Driver.h"
//#include <iostream>
//#include "Udp.h"
//#include "Parser.h"
//#include <unistd.h>
//#include <iostream>
//
//
//using namespace std;
//using namespace boost::archive;
//std::stringstream ss;
//
//int main(int argc, char *argv[]) {
//
//
//
//    string input;
//    Parser *prs1;
//    cout << argv[1] << endl;
//    Udp udp(0, atoi(argv[1]));
//    udp.initialize();
//    //create driver
//    cin >> input;
//    prs1 = new Parser();
//    prs1->parse(input, 5);
//    int id = atoi(prs1->inputVector.at(0).c_str());
//    int age = atoi(prs1->inputVector.at(1).c_str());
//    char status = prs1->inputVector.at(2)[0];
//    int experiance = atoi(prs1->inputVector.at(3).c_str());
//    int vehicleId = atoi(prs1->inputVector.at(4).c_str());
//    //create driver for serilization
//    Driver *driver = new Driver(id, age, status, experiance, vehicleId);
//    //serialization
//    std::string serial_str;
//    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
//    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
//    boost::archive::binary_oarchive sendDriver(s);
//    sendDriver << driver;
//    s.flush();
//
//    delete prs1;
//
//
////    char buffer[1024];
////    udp.sendData("hello");
////    udp.reciveData(buffer, sizeof(buffer));
////    cout << buffer << endl;
//
//
//    return 0;
//}