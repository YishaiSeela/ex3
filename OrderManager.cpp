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
    //update time
    time++;

    for (int i = 0;i<listOfRides.size();i++)
    {
        //if driver is occupied
        if (!listOfDrivers[0]->isAvailable())
        {
            //move driver to next point
            listOfRides[i]->updateDistance(1);
            distance = listOfRides[i]->getDistance();
            listOfDrivers[0]->setLocation(listOfRides[i]->getPath()[distance]);
            Point endPoint = Point(listOfRides[i]->getEndPoint()->getXCoordinate(),
                             listOfRides[i]->getEndPoint()->getYCoordinate());
            //if driver reached it's destination - set him as available and remove ride
            if ((listOfDrivers[0]->getLocation()) == (endPoint))
            {
                listOfDrivers[0]->setAvailability(true);
                listOfRides.erase(listOfRides.begin());
            }
        }
        //if it's the time to start the ride
        if (listOfRides[i]->getStartTime() == time)
        {
            //move driver to start point
            distance = 0;
            Point startPoint = Point(listOfRides[i]->getStartPoint()->getXCoordinate(),
                               listOfRides[i]->getStartPoint()->getYCoordinate());
            listOfDrivers[0]->setAvailability(false);
            listOfDrivers[0]->setLocation(startPoint);
        }

    }
}
