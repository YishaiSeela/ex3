#ifndef DRIVER
#define DRIVER
#include "../Veicle/Vehicle.h"
#include "../Veicle/CabDecorator.h"
#include "../Map/Point.h"
#include "Person.h"
#include "Passanger.h"
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

class Driver: public Person
{

    Point location;
   // CabDecorator cab;
	//Vehicle vehicleInfo; FIX!
	bool driverToPassanger;
	int experience;
	int vehicle_id;
	bool available;
	int rate;
	int rideId;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<Person>(*this);
		ar & experience;
		ar & vehicle_id;
		ar & location;
		ar & available;
		ar & rate;
		ar & rideId;
	}
public:
	Driver(int id, int age, char martialStatus, int experience, int vehicle_id);
	Driver();
	~Driver();
    bool isAvailable();
	void dropOfPass();
	void setLocation(Point point);
	Point getLocation();
	void pickUpPassanger();
	Point setDestination();
	Point getDestination();
	int getRate();
	bool driverToPass();
	void setAvailability(bool value);
	int getVehicleId();
	int getId();
	void setRide(int rideId);
	int getRide();

};
#endif

