#include "Peg.h"
#include "Disk.h"

Peg::Peg()
{
	mHeight = 400;
	mWidth = 10;
	xyCoords.first = 390;
	xyCoords.second = 200;
}
Peg::Peg(int height, int width, int x, int y, int name)
{
	mHeight = height;
	mWidth = width;
	xyCoords.first = x;
	xyCoords.second = y;
	mName = name;
}
int Peg::getHeight()
{
	return mHeight;
}
int Peg::getWidth()
{
	return mWidth;
}
int Peg::getX()
{
	return xyCoords.first;
}
int Peg::getY()
{
	return xyCoords.second;
}
void Peg::draw(GWindow &gw)
{
	gw.setColor("BLACK");
	gw.fillRect(getX(), getY(), getWidth(), getHeight());
}
std::vector<Disk>& Peg::getDisks()
{
	return disksOn;
}
Disk Peg::addDisk(Disk &disk)
{
	disksOn.push_back(disk);
	disk.setXY((mName * 300) + 90, disk.getY());
	return disk;
}
void Peg::removeDisk()
{
	disksOn.pop_back();
}
