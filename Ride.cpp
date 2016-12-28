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
	this->MyStartingPoint=startingPoint;
	this->MyEndPoint=endPoint;
	this->numOfPassengers=numOfPassangers;
	this->tarif=tarif;
	this->startTime = startTime;
	this->path=path;

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

float Ride::getStartTime(){
    return startTime;
}

std::vector<Point> Ride::getPath(){
    return path;
}

void Ride::updateDistance(int type){
	metersPassed = metersPassed + type;
}

int Ride::getDistance(){
	return metersPassed;
}