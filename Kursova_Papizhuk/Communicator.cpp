#include "Communicator.h"

Communicator::Communicator(int id, std::string type, int currentX, int communicationRange):
	Drone(id, type, currentX){

	this->communicationRange = communicationRange;
	setVelocity(2);
	setBatteryDrain(1);
}

int Communicator::getCommunicationRange() { return this->communicationRange; }
void Communicator::setCommunicationRange(int communicationRange) { this->communicationRange = communicationRange; }

void Communicator::info(){
	std::cout << "____[I'm Communicator]____" << std::endl;
	std::cout << "Current position: (" << getCurrentX() << "; " << getCurrentY() << ")" << std::endl;
	std::cout << "Destination position: (" << getDestinationX() << "; " << getDestinationY() << ")" << std::endl;
}

void Communicator::info(Drone *obj){
	if (obj->getBatteryCharge() > 0) {
		std::cout << "\t\t[Drone ID: " << obj->getId() << " -> (" << obj->getCurrentX() << ", "
			<< obj->getCurrentY() << ")]" << std::endl;
		std::cout << "\t\t===[Battery status: " << obj->getBatteryCharge() <<"]"<< std::endl;
	}
	else {
		std::cout << "\t\t[Drone ID: " << obj->getId() << " lost energy]" << std::endl;
		std::cout << "\t\t[Current position -> (" << obj->getCurrentX() << ", "
			<< obj->getCurrentY() << ")]" << std::endl;
	}
}

void Communicator::finalInformation(Drone* obj){
	if (obj->getBatteryCharge() > 0) {
		if (obj->getCurrentY() == 100 &&
			(obj->getCurrentX() == obj->getDestinationX())) {
			std::cout << "\t\t[Drone " << obj->getType() << " ID: " << obj->getId() << " -> (" << obj->getCurrentX()
				<< ", " << obj->getCurrentY() << "): reached destination]" << std::endl;
		}
		else {
			std::cout << "\t\t[Drone " << obj->getType() << " ID: " << obj->getId() << " -> (" << obj->getCurrentX()
				<< ", " << obj->getCurrentY() << "): didn't reach the goal]\n"
				<< "\t\t[Battery status: " << obj->getBatteryCharge()<<"]" << std::endl;
		}
	}
	else {
		std::cout << "\t\t[Drone " << obj->getType() << " ID: " << obj->getId() << " -> (" << obj->getCurrentX() << ", "
			<< obj->getCurrentY() << "): lost energy]" << std::endl;
	}
}

void Communicator::getInfoAboutEMP(Drone* obj){
	std::cout << "\t\t\t===[Drone(id: " << obj->getId() << ") got on the EMP]" << std::endl;
	std::cout << "\t\t\t===[EMP coordinates (" << obj->getCurrentX() << "; " << obj->getCurrentY() << ")]" << std::endl;
}

void Communicator::getInfoAboutBattery(Drone* obj){
	std::cout << "\t\t\t===[Drone(id: " << obj->getId() << ") got on charging]" << std::endl;
	std::cout << "\t\t\t===[Battery coordinates (" << obj->getCurrentX() << "; " << obj->getCurrentY() << ")]" << std::endl;
}

Communicator::~Communicator() {}