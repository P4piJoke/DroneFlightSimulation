#include "Carrier.h"

Carrier::Carrier(int id, std::string type, int currentX, int carryingCapacity) :
	Drone(id, type, currentX){

	this->carryingCapacity = carryingCapacity;
	setVelocity(1);
	setBatteryDrain(2);
}

int Carrier::getCarryingCapacity(){ return carryingCapacity; }
void Carrier::setCarryingCapacity(int carryingCapacity) { this->carryingCapacity = carryingCapacity; }

void Carrier::info(){
	std::cout << "____[I'm Carrier]____" << std::endl;
	std::cout << "Current position: (" << getCurrentX() << "; " << getCurrentY() << ")" << std::endl;
	std::cout << "Destination position: (" << getDestinationX() << "; " << getDestinationY() << ")" << std::endl;
}

Carrier::~Carrier() {}