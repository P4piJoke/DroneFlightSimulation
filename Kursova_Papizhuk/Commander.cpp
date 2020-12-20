#include "Commander.h"

Commander::Commander(int id, std::string type, int currentX, std::string gpsType, std::string commandAndControlType):
	Navigator(id, type, currentX, gpsType){

	this->commandAndControlType = commandAndControlType;
	setVelocity(2);
	setBatteryDrain(1);
}

std::string Commander::getCommandAndControlType() { return this->commandAndControlType; }
void Commander::setCommandAndControlType(std::string commandAndControlType) { this->commandAndControlType = commandAndControlType; }

void Commander::info(){
	std::cout << "____[I'm Commander]____" << std::endl;
	std::cout << "Current position: (" << getCurrentX() << "; " << getCurrentY() << ")" << std::endl;
	std::cout << "Destination position: (" << getDestinationX() << "; " << getDestinationY() << ")" << std::endl;
}

void Commander::info(Drone* obj){
	obj->setDestinationX(rand() % 100 + 1);

	std::cout << "\t\t[Drone " << obj->getType() << ": (" << obj->getCurrentX() << ", " << obj->getCurrentY() << ") -> ";
	std::cout << "(" << obj->getDestinationX() << ", " << obj->getDestinationY() << ")]" << std::endl;
}

Commander::~Commander() {}