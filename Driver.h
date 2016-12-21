#ifndef DRIVER
#define DRIVER
#include "Vehicle.h"
#include "CabDecorator.h"
#include "Point.h"
#include "Person.h"
#include "Passanger.h"

class Driver: public Person
{

    Point location;
	float yearOfExp ;
   // CabDecorator cab;
	//Vehicle vehicleInfo; FIX!
	bool driverToPassanger;
	int experience;
	int vehicle_id;
    char martialStatus;//[]={'S','M','D','W'};
	bool available;
	int rate;
public:
	Driver(int id, int age, char martialStatus, int experience, int vehicle_id);
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

	int getId();

};
#endif

