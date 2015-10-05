#include "gwindow.h"
#include "Disk.h"
#include "Peg.h"

//Gets user input to determine number of disks to use and returns it
int promptForDisks()
{
	std::cout << "Please enter the number of disks (2 to 10) to use: ";
	std::string numDisks;
	std::cin >> numDisks;
	return stringToInteger(numDisks);
	//TODO: check input is valid
}

//Misnomer; gets user input for starting peg
int promptStartingDisk()
{
	std::cout << "Please enter a number from 1 to 3 to indicate the starting peg: ";
	std::string startingPeg;
	std::cin >> startingPeg;
	return stringToInteger(startingPeg);
	//TODO: Check input is valid
}

//constructs a disk object and adds them to the diskVec vector; returns diskVec
std::vector<Disk> makeDisks(int numDisks, int startingPeg)
{
	//set x coordinate according to the starting peg
	int x = 0;
	if (startingPeg == 1)
	{
		x = 90;
	}
	else if (startingPeg == 2)
	{
		x = 390;
	}
	else if (startingPeg == 3)
	{
		x = 690;
	}
	//set y coordinate according to the number of disks there are
	int y = 500 - (numDisks * 30);
	//arbitrary heigth/width, determines based on what I thought looked best :)
	int height = 30;
	int width = 20;
	std::vector<Disk> diskVec;
	for (int i = 0; i < numDisks; i++)
	{
		//Assigns color enum to color var based on i
		COLOR color = static_cast<COLOR>(i);
		//inserts new Disk object at beginning of diskVec
		diskVec.insert(diskVec.begin(), Disk(x, y, height, width, color));
		//changes width, x, and y to fit next disk
		width += 20;
		y += 30;
		x -= 10;
	}
	return diskVec;
}

//draws current state
void draw(GWindow &gw, std::vector<Peg> &pegVec)
{
	gw.clear();
	//draw three pegs using Peg method
	for (int i = 0; i < 3; i++)
	{
		pegVec[i].draw(gw);
	}
	//loop through pegs in pegVec
	for (int i = 0; i < 3; i++)
	{
		//determine if the peg has Disks on it
		if (pegVec[i].getDisks().size() > 0)
		{
			//if it does, loop through each disk
			for (int v = 0; v < pegVec[i].getDisks().size(); v++)
			{
				//update x and y coords for disk based on the peg it's on and how many disks are under it
				int tempX = (i * 300) + (90 - (pegVec[i].getDisks()[v].getWidth() / 2));
				int tempY = 470 - (v * 30);
				pegVec[i].getDisks()[v].setXY(tempX, tempY);
				//draw disk
				pegVec[i].getDisks()[v].draw(gw);
			}
		}
	}
}

//moves the last disk from one peg and adds it to another
void moveDisk(std::vector<Peg> &pegVec, int x, int y, GWindow &gw)
{
	//Add the last disk on peg x to peg y using peg class method
	pegVec[y].addDisk(pegVec[x].getDisks()[pegVec[x].getDisks().size() - 1]);
	//Remove the last disk on peg x
	pegVec[x].removeDisk();
	//draw the updated state
	draw(gw, pegVec);
	//pause for aesthetics
	pause(100);
}

//recursive towers of hanoi algorithm
//takes GWindow gw, pegVec, an int representing the starting peg, an int representing the destination peg, and an int indicating how many disks we need to move
void towerSolver(GWindow &gw, std::vector<Peg> &pegVec, int A, int C, int N)
{
	//assign middle peg value to B; defaults to 0
	int B = 0;
	//assign B the remaining value form (0, 1, 2) that is not used by A or C
	for (int i = 0; i < 3; i++)
	{
		if (i != A && i != C)
		{
			B = i;
		}
	}
	//if one disk to move, just move it
	if (N == 1)
	{
		moveDisk(pegVec, A, C, gw);
	}
	//if more than one disk, implement recursive solution
	else
	{
		towerSolver(gw, pegVec, A, B, (N - 1));
		moveDisk(pegVec, A, C, gw);
		towerSolver(gw, pegVec, B, C, (N - 1));
	}
}

//main function
int main(int argc, char** argv)
{
	// Create a 500x500 window
	GWindow gw(800, 500);
	
	//create three Peg objects and append them to pegVec
	std::vector<Peg> pegVec;
	Peg pegOne = Peg(400, 10, 85, 100, 0);
	pegVec.push_back(pegOne);
	Peg pegTwo = Peg(400, 10, 385, 100, 1);
	pegVec.push_back(pegTwo);
	Peg pegThree = Peg(400, 10, 685, 100, 2);
	pegVec.push_back(pegThree);
	//assign value from promptStartingDIsk to startingPeg int 
	int startingPeg = promptStartingDisk();
	//make vector of all the disks in the system
	std::vector<Disk> diskVec = makeDisks(promptForDisks(), startingPeg);
	//loop through diskVec, naming each and adding them all to the starting peg
	for (int i = 0; i < diskVec.size(); i++)
	{
		diskVec[i].nameDisk(i);
		pegVec[startingPeg-1].addDisk(diskVec[i]);
	}
	//draw the initial state
	draw(gw, pegVec);
	pause(1000);
	//assign destination variable, default to third peg (2)
	int endPeg = 2;
	//if the starting peg is the third one, reassign the destination to the first peg
	if (startingPeg == 3)
	{
		endPeg = 0;
	}
	//call recursive tower of hanoi solution
	towerSolver(gw, pegVec, startingPeg - 1, endPeg, pegVec[startingPeg-1].getDisks().size());
	return 0;
}
