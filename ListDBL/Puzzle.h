#include "ListDBL.h"
 
#ifndef PUZZLE_H
#define PUZZLE_H

#define MAXSTRING	16
#define MAXQUENCE	50000
#define MAXSTATE	1000

struct Quence {
	int front, rear;
	int data[MAXQUENCE];
};

struct Puzzle {
	struct List Solution;	
	struct List Puzzles;
	char ssolution[MAXSTRING];
	char ppuzzle[MAXSTRING];
};
	
void InitPuzzle( struct Puzzle &AP );
void InPuzzle(struct Puzzle &AP,char answ[],char init[]); 
void DestoryPuzzle( struct Puzzle &AP );
void shiftLift(struct Puzzle &AP);	
void shiftRight(struct Puzzle &AP);			
void swapEnds(struct Puzzle &AP);			
void display(struct Puzzle AP);				
bool isSolved(struct Puzzle AP);
bool isEmptyPuzzle( struct Puzzle &AP ); 
void ClearPuzzle( struct Puzzle &AP );
	
int  Trans( struct Puzzle &AP, int Dir[], int ii );
void BackDoing( struct Puzzle &AP, Quence &Q );
bool ShortestPath( struct Puzzle &AP );
void OutPath( struct Puzzle &AP, int Dir[], int ii);

#endif
