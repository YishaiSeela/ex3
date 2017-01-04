#ifndef ORDERMANAGER
#define ORDERMANAGER
#include "Ride.h"
#include <list>
#include <queue>
#include "Passanger.h"

using namespace std;
class OrderManager
{

	float time;
	int distance;
public:
	std::vector<Driver*> listOfDrivers;
	std::vector<Ride*> listOfRides;
	std::vector<Vehicle*> listOfCabs;

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

	void addCab(Vehicle *vehicle);
    void timePassed();
    int findDriver(int i);


    ~OrderManager();
};

#endif
