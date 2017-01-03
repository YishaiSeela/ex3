#include "OrderManager.h"
#include <list>
#include <iostream>

using namespace std;


OrderManager::OrderManager()
/*
 * ctor
 */
{
}

OrderManager::~OrderManager()
/*
 * dtor
 */
{
    //delete drivers
    for (int i = 0; i < (listOfDrivers.size()); i++) {
        delete listOfDrivers[i];
        listOfDrivers.clear();
    }
    //delete cabs
    for (int i = 0; i < (listOfCabs.size()); i++) {
        delete listOfCabs[i];
        listOfCabs.clear();
    }
    //delete rides
    for (int i = 0; i < (listOfRides.size()); i++) {
        delete listOfRides[i];
        listOfRides.clear();
    }
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
    int driverNo = 0;
    for (int i = 0;i<listOfRides.size();i++) {
        //if it's the time to start the ride
        if (listOfRides[i]->getStartTime() == time) {
            //move driver to start point
            distance = 0;
            driverNo = findDriver(i);
            Point startPoint = Point(listOfRides[i]->getStartPoint()->getXCoordinate(),
                                     listOfRides[i]->getStartPoint()->getYCoordinate());
            listOfDrivers[driverNo]->setAvailability(false);
            listOfDrivers[driverNo]->setLocation(startPoint);
        }
    }
    //update time
    time++;

    for (int i = 0;i<listOfRides.size();i++)
    {
        //if driver is occupied
        if (!listOfDrivers[driverNo]->isAvailable())
        {
            //get type of cab;
            int type = 0;
            Point endPoint = Point(listOfRides[i]->getEndPoint()->getXCoordinate(),
                                   listOfRides[i]->getEndPoint()->getYCoordinate());

            for (int j=0;j<(listOfCabs.size());j++){
                if (listOfCabs[j]->getId() == listOfDrivers[driverNo]->getVehicleId()){
                    type = listOfCabs[j]->getType();
                }
            }

            //get next point of drive according to type
            for (int j=0;j<type;j++){
                if ((listOfDrivers[driverNo]->getLocation()) != (endPoint)) {
                    listOfRides[i]->updateDistance();
                }
                //move driver to next point
                distance = listOfRides[i]->getDistance();
                listOfDrivers[driverNo]->setLocation(listOfRides[i]->getPath()[distance]);

            }

            //if driver reached it's destination - set him as available and remove ride
            if ((listOfDrivers[driverNo]->getLocation()) == (endPoint))
            {
                listOfDrivers[driverNo]->setAvailability(true);
                delete listOfRides[i];
                listOfRides.erase(listOfRides.begin());
            }
        }

    }


}

int OrderManager::findDriver(int i)
/*
 * find driver for trip
 */
{
    Point startPoint = Point(listOfRides[i]->getStartPoint()->getXCoordinate(),
                             listOfRides[i]->getStartPoint()->getYCoordinate());
    int driverNo = -1;
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
        driverNo = 0;
    }
    return driverNo;
}