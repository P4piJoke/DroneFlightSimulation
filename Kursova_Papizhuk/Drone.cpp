#include "Drone.h"

Drone::Drone() {
	id = 0;
	type = "uknown";
	velocity = 0;
	batteryCharge = batteryDrain = 0;
	currentX = destinationX = 0;
	currentY = destinationY = 0;
}

Drone::Drone(int id, std::string type, int currentX){
	this->id = id;
	this->type = type;
	this->currentY = 1;
	this->currentX = currentX;
	this->destinationY = 100;
	this->batteryCharge = 100;
}

int Drone::getId() { return this->id; }
void Drone::setId(int id) { 
	if (id >= 0) {
		this->id = id; 
	} 
	else {
		std::cout << "ID can't be less then 0" << std::endl;
		exit(1);
	}
}

std::string Drone::getType() { return this->type; }
void Drone::setType(std::string type) { this->type = type; }

int Drone::getVelocity(){ return this->velocity; }
void Drone::setVelocity(int velocity) {
	if (velocity > 0) {
		this->velocity = velocity;
	}
	else {
		std::cout << "Velocity can't be less than 0!" << std::endl;
		exit(1);
	}
}

int Drone::getBatteryCharge() { return this->batteryCharge; }
void Drone::setBatteryCharge(int batteryCharge) { 
	if (batteryCharge >= 100) {
		this->batteryCharge = 100;
	}
	else if (batteryCharge > 0) {
		this->batteryCharge = batteryCharge;
	}
	else {
		this->batteryCharge = 0;
	}
}

int Drone::getBatteryDrain() { return batteryDrain; }
void Drone::setBatteryDrain(int batteryDrain) { this->batteryDrain = batteryDrain; }

int Drone::getCurrentX() { return this->currentX; }
void Drone::setCurrentX(int currentX) { 
	if (currentX > 0) {
		if (this->currentX < destinationX) {
			this->currentX = currentX;
			if (currentX >= destinationX) { this->currentX = destinationX; }
		}
		else if (this->currentX > destinationX) {
			this->currentX = currentX;
			if (currentX <= destinationX) { this->currentX = destinationX; }
		}
		else { this->currentX = destinationX; }
	}
	else {
		std::cout << "Current X can't be less than 0" << std::endl;
		exit(1);
	}
}

int Drone::getCurrentY() { return this->currentY; }
void Drone::setCurrentY(int currentY) { 
	if (currentY > 0) {
		if (currentY >= destinationY) {
			this->currentY = destinationY;
		}
		else {
			this->currentY = currentY;
		}
	}
	else {
		std::cout << "Current Y can't be less than 0" << std::endl;
		exit(1);
	}
	
}

int Drone::getDestinationX() { return this->destinationX; }
void Drone::setDestinationX(int destinationX) { 
	if (destinationX > 0) {
		this->destinationX = destinationX;
	}
	else {
		std::cout << "Destination X can't be less than 0" << std::endl;
		exit(1);
	}
}

int Drone::getDestinationY() { return this->destinationY; }
void Drone::setDestinationY(int destinationY) { 
	if (destinationY > 0) {
		this->destinationY = destinationY;
	}
	else {
		std::cout << "Destination Y can't be less than 0" << std::endl;
		exit(1);
	}
}

void Drone::move(){
	if (getBatteryCharge() > 0){ //якщо заряд батареї не 0й то переміщення дозволяеться

		if (getCurrentX() < getDestinationX()) { //якщо нинішний Х менше кінцевого
			setCurrentX(getCurrentX() + getVelocity()); //переміщуємось по Х
			setCurrentY(getCurrentY() + getVelocity()); //переміщуємось по У
			setBatteryCharge(getBatteryCharge() - getBatteryDrain()); //витрачаємо заряд батареї
		}

		else if (getCurrentX() > getDestinationX()) { //якщо нинішний Х більше кінцевого
			setCurrentX(getCurrentX() - getVelocity());
			setCurrentY(getCurrentY() + getVelocity());
			setBatteryCharge(getBatteryCharge() - getBatteryDrain());
		}

		else { //якщо нинішний Х дорівнює кінцевому
			setCurrentY(getCurrentY() + getVelocity());
			setBatteryCharge(getBatteryCharge() - getBatteryDrain());
		}
	}
}

Drone::~Drone(){}