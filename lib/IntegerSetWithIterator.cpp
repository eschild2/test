#include "IntegerSetWithIterator.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

namespace ece309{
// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
	:IntegerSet(htsize)
{
	probeDistance = 20;
	failedInsertions = 0;
	collisions = 0;
	table = new int[size];
	for (int i = 0; i < size; i++)
		table[i] = empty_since_start;  // -1 means empty
    
}

int IntegerSetHT::getCollisions(){
    return collisions;
}

int IntegerSetHT::getfailedInsertions(){
    return failedInsertions;
}

bool IntegerSetHT::insert(int data)
{
	int index = hash(data);
	int bucketsProbed = 0;
	while (bucketsProbed++ < probeDistance)
        
	{
        if(bucketsProbed == 2){
            collisions++;
        }
		if (table[index] < 0)
		{
       
			// if the entry is not being used, put the
		   // data there
			table[index] = data;
			return true;
		}
		index = (index + 1) % size;
	}
	// otherwise give up
	++failedInsertions;
	return false;
}

bool IntegerSetHT::search(int data) const
{
	int index = hash(data);
	int bucketsProbed = 0;
	while (table[index] != empty_since_start &&
		bucketsProbed++ < probeDistance)
	{
		if (table[index] == data)
		{
			return true;
		}
		index = (index + 1) % size;
	}

	// data can only be in one location, check it
	return false;
}

void IntegerSetHT::remove(int data)
{
	int index = hash(data);
	int bucketsProbed = 0;
	while (table[index] != empty_since_start &&
		bucketsProbed++ < probeDistance)
	{
		if (table[index] == data)
		{
			table[index] = empty_after_removal;
			//return;
		}
		index = (index + 1) % size;
	}
}
}