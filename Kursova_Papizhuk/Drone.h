#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <string>

class Drone { // Parent class Drone
private:
	int id; // Drone ID
	std::string type; // Drone type
	int velocity; // Drone velocity
	int batteryCharge; // Drone battery charge
	int batteryDrain; // Drone battery drain
	int currentX, currentY; // Drone current X & Y
	int destinationX, destinationY; // Drone destination X & Y

public:
	// Announcements of constructors
	Drone();
	Drone(int id, std::string type, int currentX);

	// Get and Set methods for Drone ID
	int getId();
	void setId(int id);

	// Get and Set methods for Drone type
	std::string getType();
	void setType(std::string type);

	// Get and Set methods for Drone velocity
	int getVelocity();
	void setVelocity(int velocity);

	// Get and Set methods for Drone Battery charge
	int getBatteryCharge();
	void setBatteryCharge(int batteryCharge);

	// Get and Set methods for Drone Battery drain
	int getBatteryDrain();
	void setBatteryDrain(int batteryDrain);

	// Get and Set methods for Drone Current x
	int getCurrentX();
	void setCurrentX(int currentX);

	// Get and Set methods for Drone Current y
	int getCurrentY();
	void setCurrentY(int currentY);

	// Get and Set methods for Drone Destination x
	int getDestinationX();
	void setDestinationX(int destinationX);

	// Get and Set methods for Drone Destination y
	int getDestinationY();
	void setDestinationY(int destinationY);

	virtual void info() = 0; // Virtual function of drone information
	void move(); // Drone movement method

	~Drone(); // Destructor for Drone
};
#endif // !DRONE_H