#include <iostream>
#include <stdio.h>
#include "Ride.h"
#include <stdlib.h>
using namespace std;

Ride::Ride(int idRide,Point startingPoint,Point endPoint ,int numOfPassangers,
           double tariff )
/**
* Ctor
*/
{

	this->idRide=idRide;
	this->MyStartingPoint=startingPoint;
	this->MyEndPoint=endPoint;
	this->numOfPassengers=numOfPassangers;
	this->tarif=tarif;

}


Ride::~Ride()
/**
* Dtor
*/
{

}

void Ride::setId(int id)
/**
* sets drivers destination
*/
{

}

int Ride::getId()
/**
* returns driver's destinaton
*/
{
    return idRide;
}

Point* Ride::getStartPoint()
/*
 * get start point of ride
 */
{
	return &MyStartingPoint;
}

Point* Ride::getEndPoint()
/*
 * get end point of ride
 */
{
	return &MyEndPoint;

}
