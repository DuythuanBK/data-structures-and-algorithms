#include "score.h"

Score::Score(int maxEnt) {
	maxEntries = maxEnt; 					// save the max size
	entries = new GameEntry[maxEntries];	// allocate array storage
	numEntries = 0;							// initially no eluments
}

Score::~Score() {
	delete[] entries;
}

void Score::add(const GameEntry& e) {
	int newScore = e.getScore();
	int i = 0;
	if(numEntries == maxEntries) {
		if(newScore <= entries[maxEntries - 1].getScore()) {
			return;
		}
	}
	else {
		numEntries++;
	}

	i = numEntries - 2;

	while( i >= 0; newScore > entries[i].getScore()) {
		entries[i+1] = entries[i];
		i--;
	}

	entries[i + 1] = e;
}

GameEntry Score::remove(int i) throw(IndexOutOfBounds) {
	if((i < 0) || (i >= numEntries))	//invalid index
		throw IndexOutOfBounds("Invalid index");

	GameEntry e = entries[i];
	for(int j = i+1; j < numEntries; j++)
		entries[j - 1] = entries[j];

	numEntries--;
	return e;
}