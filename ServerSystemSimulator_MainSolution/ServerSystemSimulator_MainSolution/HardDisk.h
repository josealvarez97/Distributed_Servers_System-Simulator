#pragma once
#include "RoundQueue.h"
#include <math.h>
class CHardDisk
{
private:
	//CRoundQueue *Disk;
	
private:
	const int SIZE = 5;

	int* disk;
	int currentDiskPosition;


public:
	CHardDisk();
	~CHardDisk();
	int RotateDisk(int targetPosition, int allowedOperations);
	int GetDiskPosition();




};

