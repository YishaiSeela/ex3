#ifndef ORDERMANAGER
#define ORDERMANAGER
#include "Ride.h"
#include <list>
#include <queue>
#include "Passanger.h"

using namespace std;
class OrderManager
{

	//check
	//queue queue ;
	//list driverListOccupaid;
public:
	std::vector<Driver*> listOfDrivers;
	std::vector<Ride*> listOfRides;
	std::vector<CabDecorator*> listOfCabs;
	//list driverListUnOccupaid;
//	list ride;

	OrderManager();
	void answerPhone(Passanger passanger);
	void sendLocation(Point point);
	Point getLocation(int id);
	void assignPassToDriver();
	void freeDriver();
	int getOrderCount();
	void getNextRide();

	void addDriver(Driver *driver);

	void addRide(Ride *ride);

	void addCab(CabDecorator *cabDecorator);

	~OrderManager();
};

#endif
