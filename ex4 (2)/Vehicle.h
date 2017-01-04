#ifndef VEHICLE
#define VEHICLE

#include <stdlib.h>
#include "Point.h"
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/serialization/base_object.hpp>
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

using namespace std;

class Vehicle
{
    typedef enum {HONDA,SUBARU,TESLA,FIAT} Manufacturer;
	Manufacturer manufacturer;
	int taxiType;
    int id;
    typedef enum {RED,BLUE,GREEN,PINK,WHITE} Color;
    Color color;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & manufacturer;
		ar & taxiType;
		ar & id;
		ar & color;

	}
public:

    //typedef enum {RED,BLUE,GREEN,PINK,WHITE} Color;
	void startDrive(Point point);
	Vehicle(char manufacturer,int taxiType,int id,char color);
    Vehicle();
	~Vehicle();

	bool turnRight(bool value);
	bool turnLeft(bool value);
	bool reverse(bool value);
	bool stopped(bool value);


	void getCurrentPosition(Point p);

	void stopDriving(Point point);

	int getType();
	int getId();

};
#endif
BOOST_SERIALIZATION_ASSUME_ABSTRACT(Vehicle);

