#include <iostream>
#include <stdio.h>
#include "Ride.h"
#include <stdlib.h>
#include <vector>

using namespace std;

Ride::Ride(int idRide,Point startingPoint,Point endPoint ,int numOfPassangers,
           double tariff ,float startTime, std::vector<Point> path)
/**
* Ctor
*/
{

	this->idRide=idRide;
	this->myStartingPoint=startingPoint;
	this->myEndPoint=endPoint;
	this->numOfPassengers=numOfPassangers;
	this->tariff=tariff;
	this->startTime = startTime;
	this->path=path;

}
/**
 * ctor difoltive
 */
Ride::Ride() {}
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
	return &myStartingPoint;
}

Point* Ride::getEndPoint()
/*
 * get end point of ride
 */
{
	return &myEndPoint;

}

float Ride::getStartTime()
/*
 * get start time of ride
 */
{
    return startTime;
}

std::vector<Point> Ride::getPath()
/*
 * get path of ride
 */
{
    return path;
}

void Ride::updateDistance()
/*
 * update distance according to cab type
 */
{
	metersPassed = metersPassed + 1;
}

int Ride::getDistance()
/*
 * return distance passed from beginning of ride
 */
{
	return metersPassed;
}