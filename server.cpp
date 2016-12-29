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

int main() {

    Udp udp(1, 1212);
    udp.initialize();

    char buffer[1024];
    //udp.reciveData(buffer, sizeof(buffer));
/*
    char buffer[1024];
    udp.reciveData(buffer, sizeof(buffer));
    cout << buffer << endl;
    udp.sendData("sup?");
*/
    Grid *g1 = new Grid();
    string input;
    OrderManager *om = new OrderManager;
    int width;
    int height;
    int task;
    int obstacles;
    Point startPoint;
    Point endPoint;
    Point obstacle;
    Parser *prs1, *prs2, *prs3, *prsOb;
    BfsSearch *bfs;
    Driver *driver;
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
            //task 1 - insert driver
            case 1: {

                cin >> input;

                udp.reciveData(buffer, sizeof(buffer));

                prs1 = new Parser();
                prs1->parse(buffer, 5);
                int id = atoi(prs1->inputVector.at(0).c_str());
                int age = atoi(prs1->inputVector.at(1).c_str());
                char status = prs1->inputVector.at(2)[0];
                int experiance = atoi(prs1->inputVector.at(3).c_str());
                int vehicleId = atoi(prs1->inputVector.at(4).c_str());
                driver = new Driver(id, age, status, experiance, vehicleId);
                om->addDriver(driver);
                delete prs1;

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
                double tarif = stod(prs2->inputVector.at(6).c_str());
                float startTime = stof(prs2->inputVector.at(7).c_str());
                startPoint = Point(atoi(prs2->inputVector.at(1).c_str()), atoi(prs2->inputVector.at(2).c_str()));
                endPoint = Point(atoi(prs2->inputVector.at(3).c_str()), atoi((prs2->inputVector.at(4).c_str())));

                g1->startPt = new Point(startPoint);
                g1->endPt = new Point(endPoint);
                bfs = new BfsSearch(g1);
                bfs->runBfs();
                bfs->printPath();
                ride = new Ride(id, startPoint, endPoint, passengers, tarif,startTime, bfs->path);
                delete bfs;
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

            case 6: {
                //task 6 - move all drivers to their end point
                int rides = om->listOfRides.size();
                for (int i = 0; i < rides; i++) {
                    if(i < om->listOfDrivers.size()) {
                        g1->startPt = om->listOfRides[0]->getStartPoint();
                        g1->endPt = om->listOfRides[0]->getEndPoint();
                        endPoint = Point(g1->endPt->getXCoordinate(), g1->endPt->getYCoordinate());

                        om->listOfDrivers[i]->setLocation(endPoint);
                        om->listOfRides.erase(om->listOfRides.begin());
                    }
                }

                cin >> task;
                break;
            }
            case 7: {

                //task 7 - delete all elemnts and exit the program
                //g1->destroyGrid(); //- FIX IT!!!

                delete g1;
                delete om;
                exit(0);

            }
            case 9:{

                om->updateLOcations();

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

/*
//    usleep(5000);
    Udp udp2(1, 5554);
    udp2.initialize();

    char buffer2[1024];
    udp2.reciveData(buffer2, sizeof(buffer2));
    cout << buffer2 << endl;
    udp2.sendData("sup?");*/

    // support more than one client?
    return 0;
}