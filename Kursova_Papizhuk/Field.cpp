/*
* Name: Papizhuk Danylo;
* ----------------------
* Discipline: OOP;
* ----------------------
* Due date: 21/12/2020;
* ----------------------
* Time spent: 48 hours; 
* ----------------------
* This is my own work;
* ----------------------
* The program demonstrates the flight of a swarm of drones from the initial to the final position on the field 100x100;
*/

// Connect the required libraries and files
#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <set>
#include "Drone.h"
#include "Navigator.h"
#include "Communicator.h"
#include "Carrier.h"
#include "Commander.h"
#include "EMP.h"
#include "Battery.h"

// Announcement of prototypes of necessary functions

EMP* setEMP(int n); // Setting the battery discharge
Battery* setBattery(int n); // Setting the battery charging
bool isFlies(Drone* drone); // Check if drone is flying
bool checkFly(Drone** drone, int amount); // Check if drones are frying
bool checkEMP(Drone* drone, EMP* emp, int n); // Check for discharge
bool checkBattery(Drone* drone, Battery* battery, int n); // Checking for charging
void droneSimulation(Drone** drones, int amount, int fieldSize, Communicator* ptr,
	EMP* emp, int empAmount, Battery* battery, int batteryAmount); // The beginning of the flight
void commanderInfo(Drone** drones, int amount, Commander* ptr); // Information from the commander
void communicatorInfo(Drone** drones, int amount, Communicator* ptr); // Information from the communicator
bool checkCurrent(Drone** drones, int amount); // Checking start position
bool checkDestination(Drone** drones, int amount); // Checking end position

// The main function

int main() {
	srand(time(NULL));

	char choice{};
	std::cout << "\t\t[The program demonstrates the flight of a swarm of drones]" << std::endl;
	std::cout << "\t[The program has additional functionality in the form of EMP and Batteries]\n" << std::endl;
	std::cout << "[Press 1 -> Start simulation]" << std::endl;
	std::cout << "[Press any other key -> Exit the program]" << std::endl;
	std::cout << "-> ";
	choice = _getch();

	if (choice != 49){
		std::cout << "There was an exit from the program" << std::endl;
		return 0;
	}
	else {
		choice = 0;
		std::cout << "Then let's get started" << std::endl;
		Sleep(2000);
	}

	// Announcement of necessary constants
	const int FIELD_SIZE = 100;
	const int AMOUNT_OF_DRONES = 4;
	const int COMMUNICATION_RANGE = 5;
	const int CARRYING_CAPACITY = 15;
	const std::string GPS_TYPE = "command";
	const std::string COMMAND_AND_CONTROL_TYPE = "high";
	const int CURRENT_X_COMMANDER = rand() % 100 + 1;
	const int CURRENT_X_COMMUNICATOR = rand() % 100 + 1;
	const int CURRENT_X_CARRIER1 = rand() % 100 + 1;
	const int CURRENT_X_CARRIER2 = rand() % 100 + 1;
	const int AMOUNT_OF_EMP = FIELD_SIZE * 5;
	const int AMOUNT_OF_BATTERY = FIELD_SIZE * 5;

	// Declaring class objects
	Commander commander(1, "Commander", CURRENT_X_COMMANDER, GPS_TYPE, COMMAND_AND_CONTROL_TYPE); // Object of the Commander class
	Communicator com(2, "Communicator", CURRENT_X_COMMUNICATOR, COMMUNICATION_RANGE); // Object of the Communicator class
	Carrier car1(3, "Carrier 1", CURRENT_X_CARRIER1, CARRYING_CAPACITY); // Object of the Carrier class
	Carrier car2(4, "Carrier 2", CURRENT_X_CARRIER2, CARRYING_CAPACITY); // Object of the Carrier class
	
	Drone* drones[AMOUNT_OF_DRONES] = {&commander,&com,&car1,&car2}; // Declaring an array of class objects
	// Bringing array members to the required type
	Commander* pCommand = dynamic_cast<Commander*>(drones[0]); // Commander type pointer
	Communicator* pCommun = dynamic_cast<Communicator*>(drones[1]); // Communicator type pointer

	// Start of simulation
	do {
		system("cls");

		//std::cout << "_______The simulation has started_______\n" << std::endl;
		std::cout << "\t\t_______[The simulation has started]_______\n" << std::endl;
		commanderInfo(drones, AMOUNT_OF_DRONES, pCommand); // Informing about the destination of drones
	} while (checkCurrent(drones,AMOUNT_OF_DRONES) && 
		checkDestination(drones,AMOUNT_OF_DRONES)); // Checking for different start and end position

	std::cout << "[Press 1 -> To continue]" << std::endl;
	std::cout << "[Press any other key -> Exit the program]" << std::endl;
	std::cout << "-> ";
	choice = _getch();
	if (choice != 49) {
		std::cout << "There was an exit from the program" << std::endl;
		return 0;
	}
	else {
		std::cout << "Let's continue\n" << std::endl;
		Sleep(1000);
	}

	Battery* battery = setBattery(AMOUNT_OF_BATTERY); // Creating an array of objects of the EMP class
	EMP *emp = setEMP(AMOUNT_OF_EMP); // Creating an array of objects of the Battery class

	//The beginning of the drone flight
	droneSimulation(drones, AMOUNT_OF_DRONES, FIELD_SIZE, pCommun, emp, AMOUNT_OF_EMP, battery, AMOUNT_OF_BATTERY);

	std::cout << "\t\t_______[Drone flight simulation result]_______" << std::endl;

	// End of simulation
	communicatorInfo(drones, AMOUNT_OF_DRONES, pCommun); // The result of the flight of drones

	std::cout << "\n\t\t_______[The simulation is over]_______" << std::endl;
	delete[]battery;
	delete[]emp;
	return 0;
}

EMP* setEMP(int n) {
	EMP* arr = new EMP[n];
	for (int i = 0; i < n; i++) {
		arr[i].setX(rand() % 100 + 1);
		arr[i].setY(rand() % 100 + 1);
		arr[i].setLossOfEnergy(rand() % 50 + 1);
	}
	return arr;
}

Battery* setBattery(int n) {
	Battery* arr = new Battery[n];
	for (int i = 0; i < n; i++) {
		arr[i].setX(rand() % 100 + 1);
		arr[i].setY(rand() % 100 + 1);
		arr[i].setEnergyRecovery(rand() % 100 + 1);
	}
	return arr;
}

bool isFlies(Drone* drone) {
	if (drone->getBatteryCharge()>0){
		if (drone->getCurrentX() != drone->getDestinationX() ||
			drone->getCurrentY() != drone->getDestinationY()) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}

bool checkFly(Drone** drone, int amount) {
	for (int i = 0; i < amount; i++){
		if (isFlies(drone[i])){
			return true;
		}
	}
	return false;
}

bool checkEMP(Drone* drone,EMP* emp, int n) {
	for (int i = 0; i < n; i++) {
		if (emp[i].getX() == drone->getCurrentX() &&
			emp[i].getY() == drone->getCurrentY()){

			drone->setBatteryCharge(drone->getBatteryCharge() - emp->getLossOfEnergy());
			return true;
		}
	}
	return false;
}

bool checkBattery(Drone* drone, Battery* battery, int n) {
	for (int i = 0; i < n; i++) {
		if (battery[i].getX() == drone->getCurrentX() &&
			battery[i].getY() == drone->getCurrentY()) {

			drone->setBatteryCharge(drone->getBatteryCharge() + battery->getEnergyRecovery());
			return true;
		}
	}
	return false;
}

void droneSimulation(Drone** drones, int amount, int fieldSize, Communicator *ptr, 
	EMP* emp, int empAmount,Battery* battery, int batteryAmount) {
	int j = 1;
	while (checkFly(drones, amount)) {
		std::cout << "\t\t____________[Stage " << j++ << "]_____________" << std::endl;

		for (int i = 0; i < amount; i++) {
			drones[i]->move();
			ptr->info(drones[i]);

			if (checkEMP(drones[i], emp, empAmount)) {
				ptr->getInfoAboutEMP(drones[i]);
			}
			else if (checkBattery(drones[i], battery, batteryAmount)) {
				ptr->getInfoAboutBattery(drones[i]);
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		
	}
}

void commanderInfo(Drone** drones, int amount, Commander* ptr) {
	for (int i = 0; i < amount; i++) {
		ptr->info(drones[i]);
		std::cout << std::endl;
	}
}

void communicatorInfo(Drone** drones, int amount, Communicator* ptr) {
	for (int i = 0; i < amount; i++) {
		ptr->finalInformation(drones[i]);
		std::cout << std::endl;
	}
}

bool checkCurrent(Drone **drones, int amount) {
	std::set<int> checker;
	for (int i = 0; i < amount; i++){
		checker.insert(drones[i]->getCurrentX());
	}
	return checker.size() == 1;
}

bool checkDestination(Drone** drones, int amount) {
	std::set<int> checker;
	for (int i = 0; i < amount; i++) {
		checker.insert(drones[i]->getDestinationX());
	}
	return checker.size() == 1;
}