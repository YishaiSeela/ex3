#ifndef VEHICLE
#define VEHICLE

#include <stdlib.h>

#include "Point.h"

using namespace std;

class Vehicle
{

	char manufacture;//[]={'H','S','T','F'};
	int id;
	char color;//[]={'R','B','G','P','W'};


public:
	void startDrive(Point point);
	Vehicle(char manufactore,int id,char color);
	~Vehicle();

	bool turnRight(bool value);
	bool turnLeft(bool value);
	bool reverse(bool value);
	bool stopped(bool value);


	void getCurrentPosition(Point p);

	void stopDriving(Point point);


};
#endif

