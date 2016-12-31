#ifndef VEHICLE
#define VEHICLE

#include <stdlib.h>
#include "Point.h"
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

using namespace std;

class Vehicle
{

	char manufacturer;// {HONDA='H',SUBARU='S',TESLA='T',FIAT='F'};
	int taxiType;
    int id;
    char color;
	//enum color {RED='R',BLUE='B',GREEN='G',PINK='p',WHITE='W'};

	friend class boost::serialization::access;
public:
	void startDrive(Point point);
	Vehicle(char manufacturer,int taxiType,int id,char color);
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

