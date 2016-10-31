#include "HardDisk.h"



CHardDisk::CHardDisk()
{
	this->disk = new int[SIZE] {1, 2, 3, 4, 5};

	currentDiskPosition = 0; // THIS MEANS THE POSITION IN THE ARRAY
}


CHardDisk::~CHardDisk()
{
}

int CHardDisk::RotateDisk(int targetPosition, int allowedOperations)
{
	targetPosition--; // we need target to be in a rage  from 0 to size - 1
	int operationsPerformed = 0;


	int internalDifference = abs(targetPosition - currentDiskPosition); // abs value of internal difference


	if (internalDifference < (SIZE - internalDifference))
	{
		// It's better to move internally
		internalDifference = targetPosition - currentDiskPosition; // sign of internalDifference
		if (internalDifference > 0)
			// If it's better to move to the "right"
			while (disk[currentDiskPosition] != disk[targetPosition] && operationsPerformed < allowedOperations)
			{
				currentDiskPosition = (currentDiskPosition++) % SIZE; // GO RIGHT
				operationsPerformed++;
			}
		else if (internalDifference < 0)
			// If it's better to move the "left"
			while (disk[currentDiskPosition] != disk[targetPosition] && operationsPerformed < allowedOperations)
			{
				if (currentDiskPosition - 1 >= 0)
					currentDiskPosition = (currentDiskPosition--) % SIZE; // GO LEFT
				else
					currentDiskPosition = ((currentDiskPosition--) % SIZE) + SIZE; // GO LEFT
				operationsPerformed++;
			}
	}
	else // we'll do the oppositte thing cause we know it's better to move externally
	{
		// It's better to move externally
		internalDifference = targetPosition - currentDiskPosition; // sign of internalDifference
		if (internalDifference > 0)
			// If it's better to move to the "right"
			while (disk[currentDiskPosition] != disk[targetPosition] && operationsPerformed < allowedOperations)
			{
				if (currentDiskPosition - 1 >= 0)
					currentDiskPosition = (currentDiskPosition--) % SIZE; // GO LEFT
				else
					currentDiskPosition = ((currentDiskPosition--) % SIZE) + SIZE; // GO LEFT
				operationsPerformed++;
			}
		else if (internalDifference < 0)
			// If it's better to move the "left"
			while (disk[currentDiskPosition] != disk[targetPosition] && operationsPerformed < allowedOperations)
			{
				currentDiskPosition = (currentDiskPosition++) % SIZE; // GO RIGHT
				operationsPerformed++;
			}
	}


	return operationsPerformed;
}

int CHardDisk::GetDiskPosition()
{
	return this->disk[currentDiskPosition];
}
