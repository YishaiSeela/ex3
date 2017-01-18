/*
 * EventNotifier.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: adidush0212
 */

#include "EventNotifier.h"
#include "../Map/Grid.h"


    EventNotifier::EventNotifier()
    /**
    * Ctor
    */
    {

    }

    EventNotifier::~EventNotifier()
    /**
    * Dtor
    */
    {

    }

    int EventNotifier::findDriver(Point startPoint,std::vector<Driver*> listOfDrivers, Grid *g1)
    /*
    *  find driver - return id of closest avialable driver
    */
    {
        int shortestPath = -1;
        int shortestId;
        for (int i=0;i<listOfDrivers.size();i++){
            if (listOfDrivers[i]->isAvailable()){
                g1->startPt = new Point(startPoint);
                g1->endPt = new Point(listOfDrivers[i]->getLocation());
                bfs = new BfsSearch(g1);
                bfs->runBfs();
                bfs->printPath();
                if ((bfs->path.size() < shortestPath) || (shortestPath == -1)){
                    shortestPath = bfs->path.size();
                    shortestId = listOfDrivers[i]->getId();
                }
                delete bfs;
                delete g1->startPt;
                delete g1->endPt;
            }
        }
        return shortestId;
    }