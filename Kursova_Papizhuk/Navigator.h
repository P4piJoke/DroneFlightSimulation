#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "Drone.h"

class Navigator : public Drone { // Child class Navigator for Drone
private:

	/*
	Velocity - two conventional units
	Battery drain is one conventional unit
	*/

	std::string gpsType; // Navigator gpsType
public:
	Navigator(int id, std::string type, int currentX, std::string gpsType); // Navigator constructor

	// Get and Set methods for gpsType
	std::string getGpsType();
	void setGpsType(std::string gpsType);

	void info()override; // Overload of the info function for the Navigator

	~Navigator(); // Destructor for Navigator
};
#endif // !NAVIGATOR_H