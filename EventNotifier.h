/*
 * EventNotifier.h
 *
 *  Created on: Nov 30, 2016
 *      Author: adidush0212
 */
#include <iostream>
#include "Point.h"
#include "Driver.h"
#include "Grid.h"
#include "BfsSearch.h"

#ifndef SRC_EVENTNOTIFIER_H_
#define SRC_EVENTNOTIFIER_H_

using namespace std;

class EventNotifier {
	std:: string notifierEvent;
	BfsSearch *bfs;
	Grid *g1;
public:
	EventNotifier();
	virtual ~EventNotifier();
	int findDriver(Point startPoint,std::vector<Driver*> listOfDrivers,Grid *g1);
};

#endif
