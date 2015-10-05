#include "Disk.h"
#include "Peg.h"


void Disk::setXY(int x, int y)
{
	xCoord = x;
	yCoord= y;
}
int Disk::getHeight()
{
	return mHeight;
}
int Disk::getWidth()
{
	return mWidth;
}
int Disk::getX()
{
	return xCoord;
}
int Disk::getY()
{
	return yCoord;
}
COLOR Disk::getColor()
{
	return mColor;
}

std::string Disk::diskColor()
{
	switch (mColor)
	{
	case 0:
		return "DARK_GRAY";
	case 1:
		return "GRAY";
	case 2:
		return "LIGHT_GRAY";
	case 3:
		return "WHITE";
	case 4:
		return "PINK";
	case 5:
		return "RED";
	case 6:
		return "ORANGE";
	case 7:
		return "YELLOW";
	case 8:
		return "GREEN";
	case 9:
		return "BLUE";
	case 10:
		return "CYAN";
	case 11:
		return "MAGENTA";
	}
}

Disk::Disk()
{
	xCoord = 0;
	yCoord = 0;
	mHeight = 30;
	mWidth = 20;
	mColor = DARK_GRAY;
}

Disk::Disk(int x, int y, int heightIn, int widthIn, COLOR colorIn)
{
	xCoord = x;
	yCoord = y;
	mHeight = heightIn;
	mWidth = widthIn;
	mColor = colorIn;
}
void Disk::nameDisk(int name)
{
	mName = name;
}
int Disk::getName()
{
	return mName;
}
void Disk::draw(GWindow &gw)
{
	gw.setColor(diskColor());
	gw.fillRect(getX(), getY(), getWidth(), getHeight());
	gw.setColor("BLACK");
	gw.drawRect(getX(), getY(), getWidth(), getHeight());
}
