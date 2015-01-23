// maze.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

// #define DEBUG	0

const unsigned int MSIZE = 12;
enum mstate { EMPTY = 0, WALL = 1, VISITED = 2, EXIT = 3};
mstate mset[MSIZE][MSIZE];

auto fcoeff = 0.4
	;	// filling coefficient
auto iter = 0;

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

void pmaze();

#ifdef _WIN32
  #include <windows.h>
#endif

bool solve(int ypos, int xpos) {
	iter ++;
#ifdef DEBUG
	#ifdef _WIN32
	COORD p = {0, 0};
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p);
	#endif
	pmaze();
#endif
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
		auto nx = xpos + m.xmove;
		auto ny = ypos + m.ymove;
		if ( ( nx < MSIZE && nx >= 0 ) && ( ny < MSIZE && ny >= 0 ) ) {
			if (solve(ny, nx))
				return true;
		}
	}

	/* exit */
	mset[ypos][xpos] = EMPTY;
	return false;
}

void pmaze() {
	for (auto i=0; i<MSIZE*MSIZE; i++) {
		if (i%MSIZE == 0) printf("\n");
		printf("%u", mset[i/MSIZE][i%MSIZE]);
	}

	printf("\n");;
}

int main() {
	// init with zeroes
	auto mnum = time(NULL);
	srand(mnum);
	memset(mset, EMPTY, MSIZE * MSIZE * sizeof(mstate));
	
	printf("solving maze [%u]. possible moves: ", mnum);
	for (mdir &m : moves) {
		printf("[%d][%d] ", m.xmove, m.ymove);
	}
	for (auto i=0; i<MSIZE*MSIZE*fcoeff; i++) {
		mset[rand() % MSIZE][rand() % MSIZE] = WALL;
	}

	mset[0][0] = EMPTY;
	mset[MSIZE - 1][MSIZE - 1] = EXIT;

	pmaze();

	if (solve(0, 0)) {
		printf("maze was solved in %d calls", iter);	
		pmaze();
	} else {
		printf("no solution in %d calls", iter);	
	};

	return 0;
}
