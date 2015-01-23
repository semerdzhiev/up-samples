// maze.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory.h>
#include <time.h>
#include <stdlib.h>


const unsigned int MSIZE = 25;

enum mstate { EMPTY = 0, WALL = 1, VISITED = 2, EXIT = 3};

mstate mset[MSIZE][MSIZE];

auto fcoeff = 0.3;

struct mdir {
	signed char xmove;
	signed char ymove;
};

mdir moves[] = { 
	{ 1, 0 },
	{ 0, 1 },
	{ 0, -1},
	{ -1, 0},
};


#include <assert.h>

void pmaze();

bool solve(int xpos, int ypos) {
//	pmaze();

	/* sanity chech */
	assert(xpos >= 0 && ypos >= 0);
	assert(xpos < MSIZE && ypos < MSIZE);

	/* enter  */
	// if there's a wall, or i've been here already
	switch (mset[ypos][xpos]) {
		case EXIT : return true; 
		case WALL : return false;
		case VISITED : return false;
	}

	mset[ypos][xpos] = VISITED;

	/* determine next state */
//	for each (mdir m in moves) {  // microsoft for-each extension
	for (mdir &m : moves) {
		int nx = xpos + m.xmove;
		int ny = ypos + m.ymove;
		if ( nx < MSIZE && nx >= 0 && ny < MSIZE && ny >= 0 ) {
			if (solve(xpos + m.xmove, ypos + m.ymove))
				return true;
		}
	}

	/* exit */
	mset[ypos][xpos] = EMPTY;
	return false;
}

void pmaze() {
	for (auto i=0; i<MSIZE*MSIZE; i++) {
		if (i%MSIZE == 0)
			std::cout << std::endl;
		std::cout << mset[i/MSIZE][i%MSIZE];
	}

	std::cout << std::endl;
}

int main() {
	// init with zeroes
	srand(time(NULL));
	memset(mset, EMPTY, MSIZE * MSIZE * sizeof(mstate));

	for (auto i=0; i<MSIZE*MSIZE*fcoeff; i++) {
		mset[rand() % MSIZE][rand() % MSIZE] = WALL;
	}

	mset[0][0] = EMPTY;
	mset[MSIZE - 1][MSIZE - 1] = EXIT;

	pmaze();

	if (solve(0, 0)) {
		std::cout << "maze was solved";	
		pmaze();
	};

	return 0;
}

