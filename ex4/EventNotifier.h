/*
 * EventNotifier.h
 *
 *  Created on: Nov 30, 2016
 *      Author: adidush0212
 */
#include <iostream>
#ifndef SRC_EVENTNOTIFIER_H_
#define SRC_EVENTNOTIFIER_H_

using namespace std;

class EventNotifier {
	std:: string notifierEvent;
public:
	EventNotifier();
	virtual ~EventNotifier();
};

#endif
