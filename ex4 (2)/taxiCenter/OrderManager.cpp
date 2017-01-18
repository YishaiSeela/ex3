#include "OrderManager.h"
#include "../Map/Grid.h"
#include <list>
#include <iostream>

using namespace std;


OrderManager::OrderManager(Grid *g1)
/*
 * ctor
 */
{
    this->g1 = g1;
    time = 0;
    distance = 0;
}

OrderManager::~OrderManager()
/*
 * dtor
 */
{
    //delete drivers
    for (int i = 0; i < (listOfDrivers.size()); i++) {
        delete listOfDrivers[i];
    }
    listOfDrivers.clear();

    //delete cabs
    for (int i = 0; i < (listOfCabs.size()); i++) {
        delete listOfCabs[i];
    }
    listOfCabs.clear();


    //delete rides
    for (int i = 0; i < (listOfRides.size()); i++) {
        //delete listOfRides[i];
    }
    listOfRides.clear();

}

void OrderManager::answerPhone(Passanger passanger)
/*
 * answer passengers phone call
 */
{

}

void OrderManager::sendLocation(Point point)
/*
 * send location to driver
 */
{

}
Point OrderManager::getLocation(int id){
/*
 * get location of a driver
 */
    Point location;
 for (int i=0;i<listOfDrivers.size();i++){
     if (listOfDrivers [i]->getId() == id) {
         location = listOfDrivers.at(i)->getLocation();
     }
 }
    return location;

}

void OrderManager::assignPassToDriver()
/*
 * assign passenger to driver
 */
{

}

void OrderManager::freeDriver()
/*
 * set a driver as free
 */
{

}

void OrderManager::getNextRide()
/*
 * get next ride of a driver
 */
{

}

int OrderManager::getOrderCount(){
/*
 * get order count
 */
    return 1;

}

void OrderManager::addDriver(Driver *driver)
/*
 * add driver to list of drivers
 */
{
    OrderManager::listOfDrivers.push_back(driver);
}

void OrderManager::addRide(Ride *ride)
/*
 * add ride to list of rides
 */
{
    OrderManager::listOfRides.push_back(ride);
}

void OrderManager::addCab(Vehicle *vehicle)
/*
 * add cab to list of cabs
 */
{
    OrderManager::listOfCabs.push_back(vehicle);
}

void OrderManager::timePassed()
/*
 * update time and move drivers
 */
{
    int driverNo;
    int driver;

    for (int i = 0;i<listOfRides.size();i++) {
        //if it's the time to start the ride

        if (listOfRides[i]->getStartTime() == time) {
            //move driver to start point
            distance = 0;
            Point startPoint = Point(listOfRides[i]->getStartPoint()->getXCoordinate(),
                                     listOfRides[i]->getStartPoint()->getYCoordinate());
            driverNo = eventNotifier.findDriver(startPoint,listOfDrivers,g1);
            for (int j=0;j<(listOfDrivers.size());j++){
                if (listOfDrivers[j]->getId() == driverNo){
                    driver = j;
                }
            }
            listOfDrivers[driver]->setRide(listOfRides[i]->getId());
            listOfDrivers[driver]->setAvailability(false);
            listOfDrivers[driver]->setLocation(startPoint);
        }
    }
    //update time
    time++;

    for (int i = 0;i<listOfDrivers.size();i++)
    {
        //if driver is occupied
        if (!listOfDrivers[i]->isAvailable())
        {
            int ride = 0;
            int type = 0;
            //get ride id
            int rideId = listOfDrivers[i]->getRide();
            //find ride
            for (int j=0;j<(listOfRides.size());j++){
                if (listOfRides[j]->getId() == rideId){
                    ride = j;
                }
            }
            Point endPoint = Point(listOfRides[ride]->getEndPoint()->getXCoordinate(),
                                   listOfRides[ride]->getEndPoint()->getYCoordinate());
            //get type of cab;

            for (int j=0;j<(listOfCabs.size());j++){
                if (listOfCabs[j]->getId() == listOfDrivers[i]->getVehicleId()){
                    type = listOfCabs[j]->getType();
                }
            }

            //get next point of drive according to type
            for (int j=0;j<type;j++){
                if ((listOfDrivers[i]->getLocation()) != (endPoint)) {
                    listOfRides[ride]->updateDistance();
                }
                //move driver to next point
                distance = listOfRides[ride]->getDistance();
                listOfDrivers[i]->setLocation(listOfRides[ride]->getPath()[distance]);

            }

            //if driver reached it's destination - set him as available and remove ride
            if ((listOfDrivers[i]->getLocation()) == (endPoint))
            {
                listOfDrivers[i]->setAvailability(true);
                //delete listOfRides[i];
                //listOfRides.erase(listOfRides.begin());
            }
        }

    }


}
/*
int OrderManager::findDriver(int i)
/*
 * find driver for trip
 *
{
    Point startPoint = Point(listOfRides[i]->getStartPoint()->getXCoordinate(),
                             listOfRides[i]->getStartPoint()->getYCoordinate());
    int driverNo = 0;
    //find a driver located in start point
    for(int j = 0; j<listOfDrivers.size();j++){
        if (listOfDrivers[j]->isAvailable()){
            if (listOfDrivers[j]->getLocation() == startPoint){
                driverNo = j;
            }
        }
    }
    //otherwise - return first driver in the list - it will change when there will be more drivers
    if (driverNo == -1){
        for(int j = 0; j<listOfDrivers.size();j++){
            if (listOfDrivers[j]->isAvailable()){
                driverNo = j;
            }
        }
    }
    return driverNo;
}*/