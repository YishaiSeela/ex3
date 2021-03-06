#ifndef RIDE
#define RIDE
#include "../Map/Point.h"
#include "../Persons/Driver.h"
#include "../Persons/Passanger.h"
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
#include <boost/serialization/vector.hpp>


class Ride

{
	int idRide;
	Point myStartingPoint;
	Point myEndPoint;
	int numOfPassengers;
	double tariff;
	int metersPassed;
	float startTime;
	std::vector<Point> path;

	//for serilaization
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & idRide;
		ar & myStartingPoint;
		ar & myEndPoint;
		ar & numOfPassengers;
		ar & tariff;
		ar & metersPassed;
		ar & startTime;
        ar & path;

	}
public:

	Ride(int idRide,Point startingPoint,Point endPoint ,int numOfPassangers,
		 double tariff,float startTime);
	//for deserialization
	Ride();
	~Ride();
	int getId();
	void setId(int id);
	Point* getStartPoint();
	Point* getEndPoint();
	float getStartTime();
	void setPath(std::vector<Point> pth);
	std::vector<Point> getPath();
	void updateDistance();
	int getDistance();

};
#endif