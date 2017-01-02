#include <boost/serialization/export.hpp>
#include "Vehicle.h"
#include "Point.h"


Vehicle::Vehicle(char manufacturer,int taxiType,int id,char color)
/**
* Ctor
*/
{
	this->manufacturer=manufacturer;// {HONDA='H',SUBARU='S',TESLA='T',FIAT='F'};
    this->taxiType=taxiType;
	this->id=id;
    this->color=color;
	enum color : char {RED='R',BLUE='B',GREEN='G',PINK='p',WHITE='W'};

    enum manufacturer : char {
        HONDA='H',
        SUBARU = 'S',
        TESLA = 'T',
        FIAT = 'F',
    };

    /*
    switch (manufacturer){
        case 'H':{
            this->manufacturer='HONDA';
            break;
        }
        case 'S':{
            this->manufacturer='SUBARU';
            break;
        }
        case 'T':{
            this->manufacturer='TESLA';
            break;
        }
        case 'F':{
            this->manufacturer='FIAT';
            break;
        }

    }*/
}

Vehicle::Vehicle()
{

};

void Vehicle::startDrive(Point point)
/**
* Start drive of vehicle
*/
{


}

bool Vehicle::stopped(bool value)
/**
* Stop drive of vehicle
*/
{
	return true;

}

bool Vehicle::turnRight(bool value)
/**
* Make vehicle to turn right
*/
{
	return true;
}

bool Vehicle::turnLeft(bool value)
/**
* Make vehicle to turn left
*/
{
	return true;
}

bool Vehicle::reverse(bool value)
/**
* Make vehicle to reverse
*/
{
	return true;
}

Vehicle::~Vehicle()
/**
* Dtor
*/
{

}


void Vehicle::getCurrentPosition(Point p)
/*
 * get current position of vehicle
 */
{

}

void Vehicle::stopDriving(Point point)
/*
 * stop vehicle's drive
 */
{

}

int Vehicle::getType()
/*
 * get type of vehicle
 */
{
    return taxiType;
}

int Vehicle::getId()
/*
 * get id of vehicle
 */
{
    return id;
}

BOOST_CLASS_EXPORT(Vehicle);