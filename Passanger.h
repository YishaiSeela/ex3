#ifndef PASSANGER
#define PASSANGER


#include "Point.h"
#include "Person.h"


class Passanger: public Person
{
protected:
	float statisfication;
	Point location;
public:
	Passanger(int id, int age, char martialStatus, float statisfication, int vehicle_id);
	Point destination();
	int rateDriver();
	void callTaxi();
	void hopOn();
	Point currentLocation();
	~Passanger();

};
#endif
