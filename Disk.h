#include <vector>
#include "gwindow.h"
#ifndef DISK_H
#define DISK_H

enum COLOR
{
	DARK_GRAY,
	GRAY,
	LIGHT_GRAY,
	WHITE,
	PINK,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	CYAN,
	MAGENTA
};

class Disk
{
	//private variables store x and y coordinates, height and width, color enum, and name
private:
	int xCoord;
	int yCoord;
	int mHeight;
	int mWidth;
	COLOR mColor;
	int mName;

public:
	//default constructor
	Disk();
	//parametrized constructor takes input for coordinates, dimensions, and color
	Disk(int x, int y, int heightIn, int widthIn, COLOR colorIn);
	//setXY changes x and y coords to input values
	void setXY(int x, int y);
	//getters
	int getHeight();
	int getWidth();
	int getX();
	int getY();
	COLOR getColor();
	//diskColor returns a string value for the color of the disk. I don't remember why I did it with enums, but it made sense at the time and it works, so
	std::string diskColor();
	void draw(GWindow &gw);
	//nameDisk is a setter for the name variable, was used for something I had before but decided against in favor of comparing widths directly
	void nameDisk(int name);
	//getter for name
	int getName();
};

#endif
