#ifndef RIDE
#define RIDE
#include "Point.h"
#include "Driver.h"
#include "Passanger.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>


class Ride

{
	int idRide;
	Point MyStartingPoint;
	Point MyEndPoint;
	int numOfPassengers;
	double tariff;
	int metersPassed = 0;
	float startTime;
	std::vector<Point> path;

	friend class boost::serialization::access;
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
	void updateDistance(int type);
	int getDistance();

};
#endif
