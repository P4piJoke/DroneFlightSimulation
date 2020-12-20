#include "Navigator.h"

Navigator::Navigator(int id, std::string type, int currentX, std::string gpsType) :
	Drone(id, type, currentX){
	this->gpsType = gpsType;
}

std::string Navigator::getGpsType() { return this->gpsType; }
void Navigator::setGpsType(std::string gpsType) { this->gpsType = gpsType; }

void Navigator::info(){
	std::cout << "____[I'm Navigator]____" << std::endl;
	std::cout << "Current position: (" << getCurrentX() << "; " << getCurrentY() << ")" << std::endl;
	std::cout << "Destination position: (" << getDestinationX() << "; " << getDestinationY() << ")" << std::endl;
}

Navigator::~Navigator(){}