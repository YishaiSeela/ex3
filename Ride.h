#ifndef RIDE
#define RIDE
#include "Point.h"
#include "Driver.h"
#include "Passanger.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>


class Ride

{
	int idRide;
	Point MyStartingPoint;
	Point MyEndPoint;
	int numOfPassengers;
	double tarif;
	int metersPassed;
	float startTime;
	std::vector<Point> path;

public:

	Ride(int idRide,Point startingPoint,Point endPoint ,int numOfPassangers,
		 double tariff,float startTime,std::vector<Point> path);
	~Ride();
	int getId();
	void setId(int id);
	Point* getStartPoint();
	Point* getEndPoint();
    float getStartTime();
    std::vector<Point> getPath();


};
#endif
