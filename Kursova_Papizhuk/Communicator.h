#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include "Drone.h"

class Communicator : public Drone{ // Child class Communicator for Drone
private:

	/*
	Velocity - two conventional units
	Battery drain - one conventional unit
	*/

	int communicationRange; // Communicator communication range
public:
	Communicator(int id, std::string type, int currentX, int communicationRange); // Communicator constructor

	// Get and Set methods for communication range
	int getCommunicationRange();
	void setCommunicationRange(int communicationRange);

	void info()override; // Overload of the info function for the Communicator
	void info(Drone *obj); // Information about the drone in flight
	void finalInformation(Drone *obj); // Information about the end of the simulation
	void getInfoAboutEMP(Drone *obj); // Information on contact with EMP
	void getInfoAboutBattery(Drone *obj); // Information on contact with Battery

	~Communicator(); // Destructor
};
#endif // !COMMUNICATOR_H