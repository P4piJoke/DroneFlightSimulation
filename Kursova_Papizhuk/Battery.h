#ifndef BATTERY_H
#define BATTERY_H

class Battery{ // Additional class Battery
private:
	int x; // Position x Battery
	int y; // Position x Battery
	int energyRecovery; // Recover energy when hit the battery

public:
	// Announcements of constructors
	Battery();
	Battery(int x, int y, int energyRecovery);

	// Get and Set methods for X
	int getX();
	void setX(int x);

	// Get and Set methods for Y
	int getY();
	void setY(int y);

	// Get and Set methods for energy recovery
	int getEnergyRecovery();
	void setEnergyRecovery(int energyRecovery);

	~Battery(); // Destructor
};
#endif // !BATTERY_H