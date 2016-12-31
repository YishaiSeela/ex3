
#include "Driver.h"

#include "Point.h"
#include "Passanger.h"


Driver::Driver(int id, int age, char martialStatus, int experience, int vehicle_id)
	: Person(id,age,martialStatus)

    /**
     * Ctor
     */
    {
		this->experience=experience;
		this->vehicle_id=vehicle_id;
        location = Point(0,0);
        available = true;
        rate = 1;
    }

    bool Driver::isAvailable()
    /**
    * returns if driver is avaliable
    */
    {
    return available;
    }

    void Driver::dropOfPass()
    /**
    * drops passenger at destination
    */
    {
        available = true;
    }

    void Driver::setLocation(Point point)
    /**
    * sets driver's location
    */
    {
         this->location=point;
    }

    Point Driver::getLocation()
    /**
    * returns driver's location
    */
    {
        return location;
    }

    void Driver::pickUpPassanger()
    /**
    * picks up passenger
    */
    {
        available = false;
    }

    Point Driver::setDestination()
    /**
    * sets drivers destination
    */
    {
        return Point();
    }

    Point Driver::getDestination()
    /**
    * returns driver's destinaton
    */
    {
        return Point();
    }

    int Driver::getRate()
    /**
    * returns driver's rate
    */
    {
        return rate;
    }

    bool Driver::driverToPass()
    /*
     * return if passenger was assignd to driver
     */
    {
        return true;
    }

    void Driver::setAvailability(bool isAvailable)
    /*
    * set drivers availability
    */
    {
        available = isAvailable;
    }


    int Driver::getId()
    /*
    * return divers id
    */
    {
        return id;
    }

    int Driver::getVehicleId()
    /*
     * return vehicle id
     */
    {
        return vehicle_id;
    }

    Driver::~Driver()
    /**
    * Dtor
    */
    {
    }

