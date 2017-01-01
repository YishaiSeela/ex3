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
Person::Person(int id, int age, char martialStatus)
{
	this->id=id;
	this->age=age;
	this->martialStatus=martialStatus;
}

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

