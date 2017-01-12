#ifndef ORDERMANAGER
#define ORDERMANAGER
#include "Ride.h"
#include <list>
#include <queue>
#include "Passanger.h"
#include "EventNotifier.h"
#include "Grid.h"

using namespace std;
class OrderManager
{
	EventNotifier eventNotifier;

	float time;
	int distance;
	Grid *g1;
public:
	std::vector<Driver*> listOfDrivers;
	std::vector<Ride*> listOfRides;
	std::vector<Vehicle*> listOfCabs;

	OrderManager(Grid *g1);
	void answerPhone(Passanger passanger);
	void sendLocation(Point point);
	Point getLocation(int id);
	void assignPassToDriver();
	void freeDriver();
	int getOrderCount();
	void getNextRide();

	void addDriver(Driver *driver);

	void addRide(Ride *ride);

	void addCab(Vehicle *vehicle);
    void timePassed();
    int findDriver(int i);


    ~OrderManager();
};

#endif
