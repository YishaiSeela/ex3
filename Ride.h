#ifndef RIDE
#define RIDE
#include "Point.h"
#include "Driver.h"
#include "Passanger.h"
#include <stdio.h>
#include <stdlib.h>



class Ride

{
	int idRide;
	Point MyStartingPoint;
	Point MyEndPoint;
	int numOfPassengers;
	double tarif;
	int metersPassed;


public:

	Ride(int idRide,Point startingPoint,Point endPoint ,int numOfPassangers,
		 double tariff );
	~Ride();
	int getId();
	void setId(int id);
	Point* getStartPoint();
	Point* getEndPoint();



};
#endif
