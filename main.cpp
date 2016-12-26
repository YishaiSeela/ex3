#include <iostream>
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

using namespace std;

int main(int argc, char *argv[])
/*
 * main
 */
{
    Grid *g1 = new Grid();
    string input;
    OrderManager *om = new OrderManager;
    int width;
    int height;
    int task;
    float time = 0;
    int obstacles;
    Point startPoint;
    Point endPoint;
    Point obstacle;
    Parser *prs1, *prs2, *prs3, *prsOb;
    BfsSearch *bfs;
    Driver *driver;
    Ride *ride;
    CabDecorator *cabDecorator;
    std::vector<Point> obstaclePoints;
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
        obstaclePoints.push_back(obstacle);
        delete prsOb;
    }
    //insert task number
    cin >> task;

    while (true) {

        switch (task) {
            //task 1 - insert driver
            case 1: {
                cin >> input;
                prs1 = new Parser();
                prs1->parse(input, 5);
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
                prs2->parse(input, 7);
                int id = atoi(prs2->inputVector.at(0).c_str());
                int passengers = atoi(prs2->inputVector.at(5).c_str());
                double tarif = stod(prs2->inputVector.at(6).c_str());

                startPoint = Point(atoi(prs2->inputVector.at(1).c_str()), atoi(prs2->inputVector.at(2).c_str()));
                endPoint = Point(atoi(prs2->inputVector.at(3).c_str()), atoi((prs2->inputVector.at(4).c_str())));
                ride = new Ride(id, startPoint, endPoint, passengers, tarif);
                om->addRide(ride);
                bfs = new BfsSearch(g1);
                //bfs->runBfs();
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
                cabDecorator = new CabDecorator(manufacturer, taxiType, id, color);
                om->addCab(cabDecorator);
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

                        //delete bfs;
                    }
                }

                cin >> task;
                break;
            }
            case 7: {
                //task 7 - delete all elemnts and exit the program
                g1->destroyGrid(); //- FIX IT!!!

                delete g1;
                delete om;
                exit(0);

            }
            case 9:{
                time++;
                cout << time;
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