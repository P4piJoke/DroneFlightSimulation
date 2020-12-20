#include "Battery.h"

Battery::Battery() { x = y = energyRecovery = 0; }

Battery::Battery(int x, int y, int energyRecovery){
	this->x = x;
	this->y = y;
	this->energyRecovery = energyRecovery;
}

int Battery::getX() { return x; }
void Battery::setX(int x) { this->x = x; }

int Battery::getY() { return y; }
void Battery::setY(int y) { this->y = y; }

int Battery::getEnergyRecovery() { return energyRecovery; }
void Battery::setEnergyRecovery(int energyRecovery) { this->energyRecovery = energyRecovery; }

Battery::~Battery() {}