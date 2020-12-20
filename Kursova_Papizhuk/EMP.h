#ifndef EMP_H
#define EMP_H

class EMP{ // Additional class EMP
private:
	int x; // Position x EMP
	int y; // Position y EMP
	int lossOfEnergy; // Energy consumption when hit on EMP

public:
	// Announcements of constructors
	EMP(); 
	EMP(int x, int y, int lossOfEnergy);

	// Get and Set methods for X
	int getX();
	void setX(int x);

	// Get and Set methods for Y
	int getY();
	void setY(int y);

	// Get and Set methods for loss of energy
	int getLossOfEnergy();
	void setLossOfEnergy(int lossOfEnergy);

	~EMP(); // Destructor
};
#endif // !EMP_H