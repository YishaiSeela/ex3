#include <iostream>
#include "Tcp.h"
#include <unistd.h>
#include <sstream>
#include <list>
#include <pthread.h>
#include "../Map/BfsSearch.h"
#include "../Map/Grid.h"
#include "../SeparateInput/StringParse.h"
#include "string"
#include "../SeparateInput/Parser.h"
#include "../Persons/Driver.h"
#include "../TaxiCenter/Ride.h"
#include "../TaxiCenter/OrderManager.h"

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

OrderManager *om;
Grid* g1;
int threadFunc[20];

//static function for thread in bfs.
static void *pThreadBfs(void* ride){
    Ride* ride1 = (Ride*) ride;

    BfsSearch* bfs;

    g1->startPt = new Point(ride1->getStartPoint()->getXCoordinate(),ride1->getStartPoint()->getYCoordinate());
    g1->endPt = new Point(ride1->getEndPoint()->getXCoordinate(),ride1->getEndPoint()->getYCoordinate());

    bfs = new BfsSearch(g1);
    bfs->runBfs();

    delete bfs;
    delete g1->startPt;
    delete g1->endPt;

    ride1->setPath(bfs->path);
}


//static function for thread in case 1-driver. for each driver will be client
static void *pThreadCase1(void* tcp1) {
    Tcp* tcp = (Tcp*) tcp1;

    //Tcp* tcp1 = (Tcp*) tcp;
    char buffer[65000];
    Driver *driver1;
    Ride *ride1;
    int clientNo = (om->clients.size() - 1);
    tcp->reciveData(buffer, sizeof(buffer),om->clients.back());
    string serial_str(buffer, sizeof(buffer));
    boost::iostreams::basic_array_source<char> device(serial_str.c_str(), serial_str.size());
    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
    boost::archive::text_iarchive ia(s2);

    ia >> driver1;

    //add driver to list
    om->addDriver(driver1);

    //send vehicle to client
    for (int i = 0;i<om->listOfCabs.size();i++) {
        if (driver1->getVehicleId() == om->listOfCabs[i]->getId()) {

            std::string vehicle_str;
            boost::iostreams::back_insert_device<std::string> inserter(vehicle_str);
            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
            boost::archive::text_oarchive oa(s);
            oa << om->listOfCabs[i];
            s.flush();

            sleep(1);
            tcp->sendData(vehicle_str,om->clients.back());

        }
    }

    while (threadFunc[clientNo] != 7) {
        if (threadFunc[clientNo] == 9){
            std::string return_driver_str;
            boost::iostreams::back_insert_device<std::string> inserter(return_driver_str);
            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
            boost::archive::text_oarchive oa(s);
            oa << om->listOfDrivers[clientNo];
            s.flush();
            sleep(1);
            tcp->sendData(return_driver_str,om->clients[clientNo]);
            int rideNo = om->listOfDrivers[clientNo]->getRide();
            ride1 = new Ride(0,Point(0,0),Point(0,0),0,0,0);

            //Ride ride3 = Ride(11,Point(22,33),Point(44,55),66,77,88);
            std::string return_ride_str;
            boost::iostreams::back_insert_device<std::string> inserter1(return_ride_str);
            boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s1(inserter1);
            boost::archive::text_oarchive oa1(s1);
            if (rideNo == -1) {

                oa1 << ride1;

            }
            else {
                for (int i = 0;i<om->listOfRides.size();i++){
                    if (om->listOfRides[i]->getId() == rideNo);
                    oa1 << om->listOfRides[i];
                }
            }
            s1.flush();
            sleep(1);
            tcp->sendData(return_ride_str,om->clients[clientNo]);

            //cout << clientNo << " ";
            delete ride1;
            threadFunc[clientNo] = 0;
        }
    }

}


std::string bufftostring(char* buffer, int length){
    string s(buffer, length);
    return s;
}


int main(int argc, char *argv[]) {
    //threa for client
    pthread_t t1;
    //thread for bfs
    pthread_t t2;
    Tcp tcp(1,"127.0.0.1",atoi(argv[1]));
    tcp.initialize();

    pthread_mutex_t myMutex;
    pthread_mutex_init(&myMutex, 0);

    g1 = new Grid();
    pthread_t bfsThread;

    string input;
    //number of drivers
    int drivers;
    //sizes of grid
    int width;
    int height;
    //number of task
    int task;
    //number of thread
    int numThread;
    //number of obstacles
    int obstacles;
    //special points on the map
    Point startPoint;
    Point endPoint;
    Point obstacle;

    Parser *prs2, *prs3, *prsOb;
    Ride *ride;
    Vehicle *vehicle;

    //insert sizes of grid
    cin >> width >> height;
    while ((width <=0) || (height <=0)){
        cout <<"-1\n";
        cin >> width >> height;
    }
    //create grid
    g1->createGrid(width,height);
    //create order manager
    om = new OrderManager(g1);
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
                pthread_t threads[drivers];
                //receive driver from each client
                for (int i = 0; i < drivers; i++) {
                    int aoc = tcp.acceptOneClient();
                    om->clients.push_back(aoc);

                    numThread = pthread_create(&threads[i], NULL, pThreadCase1, (void *) &tcp);
                    if (numThread == -1) {
                        cout << "error";
                    }
                    threadFunc[i] = 0;
                    sleep(1);
                    //pthread_join(threads[i],NULL);
                }
                cin >> task;
                break;
            }
                //task 2 - insert ride
             case 2: {

                cin >> input;

                prs2 = new Parser();

                prs2->parse(input, 8);
                if (prs2->inputVector.at(0) == "error") {
                    cout << "-1\n";
                } else {
                    int id = atoi(prs2->inputVector.at(0).c_str());
                    int passengers = atoi(prs2->inputVector.at(5).c_str());
                    double tariff = stod(prs2->inputVector.at(6).c_str());

                    float startTime = stof(prs2->inputVector.at(7).c_str());
                    if ((startTime <= 0) || (tariff < 0) || (id < 0) || (passengers < 0)) {
                        cout << "-1\n";

                    } else {
                        startPoint = Point(atoi(prs2->inputVector.at(1).c_str()),
                                           atoi(prs2->inputVector.at(2).c_str()));
                        endPoint = Point(atoi(prs2->inputVector.at(3).c_str()),
                                         atoi((prs2->inputVector.at(4).c_str())));
                        if ((startPoint.getXCoordinate() >= height) || (endPoint.getXCoordinate() >= height) ||
                                (startPoint.getYCoordinate() >= width) || (endPoint.getYCoordinate() >= width)){
                            cout << "-1\n";
                        } else {

                            ride = new Ride(id, startPoint, endPoint, passengers, tariff, startTime);

                            numThread = pthread_create(&bfsThread, NULL, pThreadBfs, (void *) ride);
                            if (numThread == -1) {
                                cout << "error";
                            }

                            pthread_join(bfsThread, NULL);

                            om->addRide(ride);
                        }
                    }
                }
                delete prs2;

                cin >> task;
                break;
            }
                //task 3 - insert a vehicle:
            case 3: {
                cin >> input;
                prs3 = new Parser();
                prs3->parse(input, 4);
                if (prs3->inputVector.at(0) == "error") {
                    cout << "-1\n";
                } else {

                    int id = atoi(prs3->inputVector.at(0).c_str());
                    int taxiType = atoi(prs3->inputVector.at(1).c_str());
                    char manufacturer = prs3->inputVector.at(2)[0];
                    char color = prs3->inputVector.at(3)[0];
                    if ((id < 0) || ((taxiType != 1) && (taxiType != 2))) {
                        cout << "-1\n";

                    } else {
                        vehicle = new Vehicle(manufacturer, taxiType, id, color);
                        om->addCab(vehicle);
                    }
                }
                delete prs3;

                cin >> task;
                break;
            }

            case 4: {
                //task 4 - request for a driver location:
                cin >> input;
                int driveId = atoi(input.c_str());
                Point location = (om->getLocation(driveId));
                if ((location.getXCoordinate() == -1) || (location.getYCoordinate() == -1)) {
                    cout << "-1\n";
                } else {
                    cout << "(" << location.getXCoordinate() << "," << location.getYCoordinate() << ")" << endl;
                }
                cin >> task;

                break;
            }

            case 7: {

                //task 7 - delete all elemnts and exit the program
                g1->destroyGrid();
                delete g1;

                sleep(1);
                for(int i = 0;i<om->listOfDrivers.size();i++) {
                    threadFunc[i] = 7;
                    tcp.sendData("7",om->clients[i] );
                }
                tcp.closeData();
                delete om;
                pthread_mutex_destroy(&myMutex);
                exit(0);

            }
            case 9:{

                //task 9 - add 1 to "time" and move drivers if needed
                om->timePassed();
                //update drivers in client
                for(int i = 0;i<om->listOfDrivers.size();i++) {
                    threadFunc[i] = 9;
                }
                cin >> task;
                break;

            }
            default: {
                //for any other input - print '-1' and ask for a valid input
                cout<<"-1\n";
                cin >> task;
                break;
            }
        }
    }
}

