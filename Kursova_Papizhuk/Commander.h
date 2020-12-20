#ifndef COMMANDER_H
#define COMMANDER_H

#include "Navigator.h"

class Commander : public Navigator { // Child class Commander for Navigator
private:

	/*
	Velocity - two conventional units
	Battery drain - one conventional unit
	*/

	std::string commandAndControlType; // Commander command and control type
public:
	Commander(int id, std::string type, int currentX, std::string gpsType, std::string commandAndControlType); // Commander constructor

	// Get and Set methods for command and control type
	std::string getCommandAndControlType();
	void setCommandAndControlType(std::string commandAndControlType);

	void info()override; // Overload of the info function for the Commander
	void info(Drone* obj); // Information about the drone at the beginning of the flight

	~Commander(); // Destructor
};
#endif // !COMMANDER_H