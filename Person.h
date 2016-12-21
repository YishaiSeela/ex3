/*
 * Person.h
 *
 *  Created on: Nov 30, 2016
 *      Author: adidush0212
 */

#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include <iostream>
using namespace std;

class Person {
protected:
	int id;
	int age;
	char martialStatus;
public:
	Person(int id, int age, char martialStatus);
	virtual ~Person();
};

#endif /* SRC_PERSON_H_ */
