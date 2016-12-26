#ifndef VEHICLE
#define VEHICLE

#include <stdlib.h>

#include "Point.h"

using namespace std;

class Vehicle
{

	char manufacturer;// {HONDA='H',SUBARU='S',TESLA='T',FIAT='F'};
	int taxiType;
    int id;
    char color;
	//enum color {RED='R',BLUE='B',GREEN='G',PINK='p',WHITE='W'};


public:
	void startDrive(Point point);
	Vehicle(char manufacturer,int taxiType,int id,char color);
	~Vehicle();

	bool turnRight(bool value);
	bool turnLeft(bool value);
	bool reverse(bool value);
	bool stopped(bool value);


	void getCurrentPosition(Point p);

	void stopDriving(Point point);


};
#endif

