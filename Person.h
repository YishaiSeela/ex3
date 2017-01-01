/*
 * Person.h
 *
 *  Created on: Nov 30, 2016
 *      Author: adidush0212
 */

#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include <iostream>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/access.hpp>
#include <boost/serialization/assume_abstract.hpp>

using namespace std;

class Person {
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & id;
		ar & age;
		ar & martialStatus;
	}
protected:
	int id;
	int age;
	char martialStatus;//[]={'S','M','D','W'};
public:
	Person(int id, int age, char martialStatus);
	Person();
	virtual ~Person();
};

#endif /* SRC_PERSON_H_ */
BOOST_SERIALIZATION_ASSUME_ABSTRACT(Person);
