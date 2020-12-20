#include "EMP.h"

EMP::EMP() { x = y = lossOfEnergy = 0; }

EMP::EMP(int x, int y, int lossOfEnergy){
	this->x = x;
	this->y = y;
	this->lossOfEnergy = lossOfEnergy;
}

int EMP::getX() { return x; }
void EMP::setX(int x) { this->x = x; }

int EMP::getY() { return y; }
void EMP::setY(int y) { this->y = y; }

int EMP::getLossOfEnergy() { return lossOfEnergy; }
void EMP::setLossOfEnergy(int lossOfEnergy) { this->lossOfEnergy = lossOfEnergy; }

EMP::~EMP() {}
