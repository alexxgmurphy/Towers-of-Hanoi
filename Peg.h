#include <vector>
#include "gwindow.h"
#include "Disk.h"
#ifndef PEG_H
#define PEG_H

//Peg class
class Peg
{
	//private variables store dimensions, coordinates, and a vector of the disks on the peg
private:
	int mHeight;
	int mWidth;
	std::pair<int, int> xyCoords;
	std::vector<Disk> disksOn;
	int mName;

public:
	//default constructor
	Peg();
	//parametrized constructor takes height, width, x and y coordinates, and a name int
	Peg(int height, int width, int x, int y, int name);
	//getHeight returns mHeight
	int getHeight();
	//getWidth returns mWidth
	int getWidth();
	//getX and getY return xyCoords.first and xyCoords.second respectively
	int getX();
	int getY();
	//draws the peg in the given window gw
	void draw(GWindow &gw);
	//returns reference to vector disksOn
	std::vector<Disk>& getDisks();
	//adds Disk object to disksOn
	Disk addDisk(Disk &disk);
	//removes last Disk object from disksOn
	void removeDisk();
};

#endif
