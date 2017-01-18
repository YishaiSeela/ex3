#include "Passanger.h"
#include "../TaxiCenter/OrderManager.h"

Passanger::Passanger(int id, int age, char martialStatus, float statisfication, int vehicle_id)
: Person(id,age,martialStatus)
	/**
    * Ctor
    */
	{
		this->statisfication=statisfication;
		location = Point(0,0);
    }

	int Passanger::rateDriver()
	/**
    * Rate driver
    */
	{
		return 1;
	}
	Point Passanger::currentLocation()
	/*
	 * the current location of the passanger
	 */
	{
		return location;
	}
	void Passanger::callTaxi()
	/**
    * Oreder a taxi
    */
	{

	}

	void Passanger::hopOn()
	/**
    * Hop on to the taxi
    */
	{

	}

	Point Passanger::destination()
	/**
    * Give destination to taxi
    */
	{
        return Point();
	}

    Passanger::~Passanger()
	/**
    * Dtor
    */
    {

    }

