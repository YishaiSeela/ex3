#include <iostream>
#include "Udp.h"
#include <unistd.h>
#include <sstream>
#include <list>

#include "BfsSearch.h"
#include "Grid.h"
#include "StringParse.h"
#include "string"
#include "Parser.h"
#include "Driver.h"
#include "Ride.h"
#include "OrderManager.h"

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


std::string bufftostring(char* buffer, int length){
    string s(buffer, length);
    return s;
}

int main(int argc, char *argv[]) {

    Udp udp(1,"127.0.0.1",atoi(argv[1]));
    udp.initialize();

    char buffer[1024];

    Grid *g1 = new Grid();

    string input;
    int drivers;
    OrderManager *om = new OrderManager;
    int width;
    int height;
    int task;
    int obstacles;
    Point startPoint;
    Point endPoint;
    //Point current;
    Point obstacle;
    Parser *prs1, *prs2, *prs3, *prsOb;
    BfsSearch *bfs;
    Driver *driver1;
    Ride *ride;
    Vehicle *vehicle;
    //insert sizes of grid
    cin >> width >> height;
    //create grid
    g1->createGrid(width,height);
    //insert number of obstacles
    cin >> obstacles;
    //insert obstacle points
    for (int i=0; i<obstacles; i++){
        cin >> input;
        prsOb = new Parser();
        prsOb->parse(input, 2);
        obstacle = Point(atoi(prsOb->inputVector.at(0).c_str()), atoi(prsOb->inputVector.at(1).c_str()));
        g1->setObstacle(obstacle);
        delete prsOb;
    }
    //insert task number
    cin >> task;

    while (true) {

        switch (task) {
            //task 1 - recive drivers via socket
            case 1: {
                //input number of drivers
                cin >> drivers;
                //recieve driver from client
                udp.reciveData(buffer, sizeof(buffer));
                string serial_str(buffer, sizeof(buffer));
                boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
                boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
                boost::archive::text_iarchive ia(s2);
                ia >> driver1;
                //add driver to list
                om->addDriver(driver1);
                //send vehicle to client
                for (int i = 0;i<om->listOfCabs.size();i++){
                    if (driver1->getVehicleId() == om->listOfCabs[i]->getId()){
                        std::string vehicle_str;
                        boost::iostreams::back_insert_device<std::string> inserter(vehicle_str);
                        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
                        boost::archive::text_oarchive oa(s);
                        oa << om->listOfCabs[i];
                        s.flush();
                        udp.sendData(vehicle_str);
                    }

                }

                //send ride to client
                std::string ride_str;
                boost::iostreams::back_insert_device<std::string> inserter(ride_str);
                boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s1(inserter);
                boost::archive::text_oarchive oa(s1);
                oa << ride;
                s1.flush();
                udp.sendData(ride_str);


                cin >> task;

                break;
            }
                //task 2 - insert ride
            case 2: {

                cin >> input;
                prs2 = new Parser();
                prs2->parse(input, 8);
                int id = atoi(prs2->inputVector.at(0).c_str());
                int passengers = atoi(prs2->inputVector.at(5).c_str());
                double tariff = stod(prs2->inputVector.at(6).c_str());
                float startTime = stof(prs2->inputVector.at(7).c_str());
                startPoint = Point(atoi(prs2->inputVector.at(1).c_str()), atoi(prs2->inputVector.at(2).c_str()));
                endPoint = Point(atoi(prs2->inputVector.at(3).c_str()), atoi((prs2->inputVector.at(4).c_str())));

                g1->startPt = new Point(startPoint);
                g1->endPt = new Point(endPoint);
                bfs = new BfsSearch(g1);
                bfs->runBfs();
                bfs->printPath();
                ride = new Ride(id, startPoint, endPoint, passengers, tariff,startTime, bfs->path);
                delete bfs;
                delete g1->startPt;
                delete g1->endPt;

                om->addRide(ride);
                delete prs2;

                cin >> task;
                break;
            }
                //task 3 - insert a vehicle:
            case 3: {
                cin >> input;
                prs3 = new Parser();
                prs3->parse(input, 4);
                int id = atoi(prs3->inputVector.at(0).c_str());
                int taxiType = atoi(prs3->inputVector.at(1).c_str());
                char manufacturer = prs3->inputVector.at(2)[0];
                char color = prs3->inputVector.at(3)[0];
                vehicle = new Vehicle(manufacturer, taxiType, id, color);
                om->addCab(vehicle);
                delete prs3;

                cin >> task;
                break;
            }
            case 4: {
                //task 4 - request for a driver location:
                cin >> input;
                int driveId = atoi(input.c_str());
                Point location = (om->getLocation(driveId));
                cout << "(" << location.getXCoordinate() << "," << location.getYCoordinate() << ")" << endl;
                cin >> task;

                break;
            }

            case 7: {

                //task 7 - delete all elemnts and exit the program
                g1->destroyGrid();
                delete g1;
                delete om;
                udp.sendData("7");
                udp.closeData();
                exit(0);

            }
            case 9:{
                //task 9 - add 1 to "time" and move drivers if needed
                om->timePassed();

                //update drivers in client
                for(int i = 0;i<om->listOfDrivers.size();i++) {
                    std::string return_driver_str;
                    boost::iostreams::back_insert_device<std::string> inserter(return_driver_str);
                    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
                    boost::archive::text_oarchive oa(s);
                    oa << om->listOfDrivers[i];
                    s.flush();
                    udp.sendData(return_driver_str);

                }
                cin >> task;
                break;

            }
            default: {
                //for any other input - ask for a valid input
                cin >> task;
                break;
            }
        }
    }
}