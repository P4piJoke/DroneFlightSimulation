#ifndef CARRIER_H
#define CARRIER_H

#include "Drone.h"

class Carrier : public Drone { // Child class Carrier for Drone
private:

	/*
	Velocity - one conventional unit
	Battery drain - two conventional units
	*/

	int carryingCapacity; // Carrier carrying capacity
public:
	Carrier(int id, std::string type, int currentX, int carryingCapacity); // Carrier constructor

	// Get and Set methods for carrying capacity
	int getCarryingCapacity();
	void setCarryingCapacity(int carryingCapacity);

	void info()override; // Overload of the info function for the Carrier

	~Carrier(); // Destructor
};
#endif // !CARRIER_H