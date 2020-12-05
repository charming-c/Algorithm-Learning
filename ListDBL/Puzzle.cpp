
#include "Puzzle.h"
#include <iostream>

using namespace std;

void InitQuence( Quence &Q ) 
{ 
	Q.front = 0; 
	Q.rear = 0; 
}

int GetHead( Quence &Q ) 
{
    return Q.data[Q.front];
}

Bool isQuenceFull( Quence Q ) 
{ 
	if ( Q.rear>=MAXQUENCE ) return TRUE; else return FALSE;  
}

Bool isQuenceEmpty( Quence Q ) 
{ 
	if ( Q.front==Q.rear ) return TRUE; else return FALSE; 
}

void EnQuence( Quence &Q, int Data ) 
{
	if (!isQuenceFull(Q)) Q.data[Q.rear++] = Data;
}  

void DeQuence( Quence &Q ) 
{ 
	if (!isQuenceEmpty(Q)) Q.front++; 
}


void InitPuzzle( struct Puzzle &AP )
{
	InitList( AP.Puzzles );
	InitList( AP.Solution );
}

void InPuzzle( struct Puzzle &AP, char answ[], char init[] )
{
	CreatList( AP.Puzzles, init );
	CreatList( AP.Solution, answ );
}
 
void shiftLift( struct Puzzle &AP )	
{
	Shift_L( AP.Puzzles );
}

void shiftRight( struct Puzzle &AP )			
{
	Shift_R( AP.Puzzles );
}

void swapEnds( struct Puzzle &AP )			
{
	SwapItem( AP.Puzzles );
}

void display( struct Puzzle AP )				
{
	cout << "Solution: " ;
	showListData( AP.Solution );
	cout << "Puzzle:   " ;
	showListData( AP.Puzzles );	
}

bool isSolved( struct Puzzle AP )	
{
	gotoBeginning( AP.Puzzles );
	gotoBeginning( AP.Solution );
	do {
		if ( getCursor(AP.Puzzles)!=getCursor(AP.Solution) ) return FALSE;
	} while (gotoNext(AP.Puzzles)&&gotoNext(AP.Solution));
	if (isEnd(AP.Puzzles)&&isEnd(AP.Solution) ) return TRUE; else return FALSE;
}

void DestoryPuzzle( struct Puzzle &AP )
{
	DestroyList( AP.Puzzles );
	DestroyList( AP.Solution );
}


bool isEmptyPuzzle( struct Puzzle &AP ) 
{
	if (isEmpty(AP.Puzzles)||isEmpty(AP.Puzzles)) return TRUE;
	else return FALSE;
}

void ClearPuzzle( struct Puzzle &AP )
{
	clear( AP.Puzzles );
	clear( AP.Solution );
}


int BackDoing( Quence &Q, int Dir[] )
{
	int ii = 0;
	int j,t;
	int i = Q.front; 
	
	if ( i==0 || i==1 ) {  Dir[0] = i; return 1; }
    while ( 1 ) { 
		Dir[ii++] = Q.data[i]%2;
		i = Q.data[i]/2;
		if ( i==0 || i==1 ) { Dir[ii++] = i; break; }
	}
	for ( i=0,j=ii-1;i<j;i++,j-- ) {  t = Dir[i]; Dir[i] = Dir[j]; Dir[j] = t; }
	return ii;
}

int Trans( struct Puzzle &AP, int Dir[], int ii )
{
	int i;
	
	ReplaceList( AP.Puzzles, AP.ppuzzle );
	for ( i=0; i<ii; i++ ) {
		if ( Dir[i]==0 ) {
			shiftRight( AP );
			if ( isSolved(AP) ) return i+1;		
		}
		else if (Dir[i]==1) {
			swapEnds( AP );
			if ( isSolved(AP) ) return i+1;
		}
    }
	return -1;
}

void OutPath( struct Puzzle &AP, int Dir[], int ii)
{
	int i;

	ReplaceList( AP.Puzzles, AP.ppuzzle );
	for ( i=0; i<ii; i++ ) {
		if ( Dir[i]==0 ) {
			cout << "Right Shift: ";
			shiftRight(AP);
			showListData(AP.Puzzles);
		}
		else {
			cout << "Swap:        ";
			swapEnds(AP);
			showListData(AP.Puzzles);
		}
    }
}

bool ShortestPath( struct Puzzle &AP )
{   
	int Data, newData;
	int Dir[MAXSTATE];
	int ii,is;
	Quence Q;

	InitQuence(Q); 
 	EnQuence(Q,0);  
	EnQuence(Q,3);  

    while( !isQuenceEmpty(Q) && !isQuenceFull(Q) ) {
		Data = GetHead(Q);
		newData = Q.front*2;
		EnQuence(Q,newData);
		if ( Data%2==0 ) {
			newData = Q.front*2+1;
			EnQuence(Q,newData);
		}
		DeQuence(Q);
		ii = BackDoing(Q,Dir);
		if ((is=Trans(AP,Dir,ii))>=0 ) break;
    }

    if ( isQuenceEmpty(Q)||isQuenceFull(Q) ) {
		cout << "Sorry, Overflow!" << endl;  
		return FALSE;
	}
	else {
		OutPath(AP,Dir,is);
        return TRUE;
	}
}

