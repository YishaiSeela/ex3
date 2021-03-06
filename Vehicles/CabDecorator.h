#ifndef CABDECORATOR
#define CABDECORATOR


#include "Vehicle.h"

class CabDecorator : public Vehicle
{
protected:
	int taxiType;
	double kmg;
	double tariff;
	double km;
public:
	CabDecorator(char manufacturer,int taxiType,int id,char color);
	~CabDecorator();
};

#endif
