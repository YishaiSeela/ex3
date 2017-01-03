/*
 * Person.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: adidush0212
 */

#include "Person.h"

/**
* Ctor
*/
Person::Person(int id, int age, char ms)
{
	this->id=id;
	this->age=age;
	switch (ms){
		case 'S':{
			this->martialStatus=SINGLE;
			break;
		}
		case 'M':{
			this->martialStatus=MARRIED;
			break;
		}
		case 'D':{
			this->martialStatus=DIVORCED;
			break;
		}
		case 'W':{
			this->martialStatus=WIDDOW;
			break;
		}

	}}

Person::Person()
/**
 * Default Ctor
 */
{

}

Person::~Person()
/**
* Dtor
*/
{
	// TODO Auto-generated destructor stub
}

