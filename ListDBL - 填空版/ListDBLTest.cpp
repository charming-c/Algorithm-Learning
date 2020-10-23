#include "Puzzle.h"
#include <iostream>

using namespace std;

void InitTestList( List &L )
{
	ElemType data; 	
	int	  i, N;
	
	InitList( L );

	cout << "Enter the number of data: " ;
ll:	cin >> N;
	if ( N<=0 ) {
		cout << "Error!  input again! "  << endl;
		goto ll;
	}
		
	cout << "Input each data!" << endl;
	for ( i=0; i<N; i++ ) {
		cout << "data" << i+1 << ":  ";
		cin >> data;
		insert( L, data ); 
	}
}

void TestList( List &L ) 
{
	showStructure( L );	
}


void Comm_ADD( List &L, ElemType data )
{
	ElemType x;
	insert( L,data );
	x = getCursor( L );	
	cout << x << endl;
}

void Comm_SUB( List &L )
{
	cout << getCursor(L) << endl;
	if ( !remove(L) ) cout << "ERROR! List is Empty!" << endl;
	else showStructure(L);	
}

void Comm_Replace( List &L, ElemType newdata )
{
	ElemType olddata;
	olddata = getCursor(L);
	cout << olddata << endl;
	replace(L,newdata);
	showStructure(L);
}

void Comm_Alta( List &L )
{
	ElemType data;
	data = getCursor(L);	
	cout << data << endl;
}
			

void Comm_N( List &L )
{
	ElemType data;
	gotoNext(L); 
	data = getCursor(L);	
	cout << data << endl;
}

void Comm_P( List &L )
{
	ElemType data;
	gotoPrior(L); 
	data = getCursor(L);	
	cout << data << endl;
}

void Comm_Head( List &L )
{
	ElemType data;
	gotoBeginning(L);
	data = getCursor(L);	
	cout << data << endl;
}

void Comm_End( List &L )
{
	ElemType data;
	gotoEnd( L ); 
	data = getCursor(L);	
	cout << data << endl;
}

void Comm_E( List &L )
{
	if (isEmpty(L) ) 
		cout << "YES! List is empty!" << endl;
	else
		cout << "NO! List is not empty!" << endl;
}

void Comm_F( List &L )
{
	if (isFull(L) ) 
		cout << "YES! List is full!" << endl;
	else
		cout << "NO! List is not full!" << endl;
}

void Comm_C( List &L )
{
	clear( L );
}


void Comm_Other( void )
{
		
}

void Comm_Q( int &t )
{
	t = TRUE;
}


void Comm_R( List &L )
{
	showStructure(L);
	Reverse(L);	
	showStructure(L);
}

void Comm_Jin( List &L )
{
	cout << "List length: " << getLength(L) << ",  Current Point Position: " << getCurPosition(L) << endl;	
}


void ExplanComm_Sq( List &L )
{
	ElemType data;
	int  T = FALSE;
	char key;
	do {
		cout <<  "input comm: ";
		cin >> key;
		switch( key ) {
			case '+' : 
				cin >> data;		
				Comm_ADD( L, data );
				break;
			case '-' : 
				Comm_SUB( L );
				break;
			case '=' : 
				cin >> data;		
				Comm_Replace( L, data );
				break;
			case '@' :
				Comm_Alta( L );
				break;
			case 'N' :
			case 'n' :	
				Comm_N( L );
				break;
			case 'P' :
			case 'p' :
				Comm_P( L );
				break;
			case '<' :
				Comm_Head( L );
				break;
			case '>' :
				Comm_End( L );
				break;
			case 'E' :
			case 'e' :
				Comm_E( L );
				break;
			case 'F' :
			case 'f' :
				Comm_F( L );
				break;
			case 'C' :
			case 'c' :
				Comm_C( L );
				break;
			case 'Q' :
			case 'q' :
				Comm_Q( T );
				return;
			case 'R' :
			case 'r' :
				Comm_R( L );
				break;
			case '#' :
				Comm_Jin( L );
				break;
			default:
				Comm_Other();
				break;
		}
		cout << endl;
	} while( !T );
}



void main(void)
{
	List L; 
	
//	cout << "Program test!" <<endl;
//	InitTestList( L );
//	TestList( L );
//	DestroyList(L);
	
	cout << "Comm test!" <<endl;
	InitList( L );
	ExplanComm_Sq(L);
	DestroyList(L); 	
}


Bool PuzzleCheckOK( char solution[], char puzzle[] )
{
	int i;
	int flag;
	int cc[256];
	int dd[256];
	char *p;

	flag = 0;
	for (i=0;i<256;i++) cc[i] = dd[i] = 0;	
	if ( strlen(solution)!=strlen(puzzle) )	return FALSE;
	p = solution;
	while ( *p )
	{
		if ( !( *p>='0' && *p<='9' || *p>='a' && *p<='z' || *p>='A' && *p<='Z' ) ) { flag = 1; break; }
		else cc[*p]++;
		p++;
	}
	if (flag) return FALSE;

	p = puzzle;
	while ( *p )
	{
		if ( !( *p>='0' && *p<='9' || *p>='a' && *p<='z' || *p>='A' && *p<='Z' ) ) { flag = 1; break; }
		else dd[*p]++;
		p++;
	}
	if (flag) return FALSE; 
	for(i=0;i<256;i++)
		if ( cc[i]!=dd[i] ) { flag = 1; break; }		
	if (flag) return FALSE; else return TRUE;
}


void Puzzle_I( Puzzle &AP )
{
	if ( !isEmptyPuzzle(AP) ) {
		cout << "Puzzle is not Empty now, Please Clear it!" << endl;
		return;
	}

	cout << "Input Solution string: " ;
	cin >> AP.ssolution;
	cout << "Input Puzzle string: " ;
	cin >> AP.ppuzzle;
	if ( PuzzleCheckOK(AP.ssolution,AP.ppuzzle) ) InPuzzle( AP, AP.ssolution, AP.ppuzzle );
	display( AP );
}

void Puzzle_L( Puzzle &AP )
{
	shiftLift( AP );
	display( AP );	
	if ( isSolved(AP) ) cout << "OK!, GOOD!" << endl;
}


void Puzzle_R( Puzzle &AP )
{
	shiftRight( AP );
	display( AP );	
	if ( isSolved(AP) ) cout << "OK!, GOOD!" << endl;
}


void Puzzle_S( Puzzle &AP )
{
	swapEnds( AP );
	display( AP );	
	if ( isSolved(AP) ) cout << "OK!, GOOD!" << endl;
}


void Puzzle_P( Puzzle &AP )
{
	ShortestPath( AP );
}

void Puzzle_C( Puzzle &AP )
{
	if ( !isEmptyPuzzle(AP) ) {
		ClearPuzzle(AP);
		cout << "Puzzle is Empty now!" << endl;
	}
}

void Puzzle_Other( Puzzle &AP )
{
}


void ExplanPuzzle( Puzzle &AP )
{
	int  T = FALSE;
	char key;
	do {
		cout << "input Puzzle comm: ";
		cin >> key;
		switch( key ) {
			case 'I' :
			case 'i' :
				Puzzle_I( AP );
				break;
			case 'L' :
			case 'l' :
				Puzzle_L( AP );
				break;
			case 'R' :
			case 'r' :
				Puzzle_R( AP );
				break;
			case 'S' :
			case 's' :
				Puzzle_S( AP );
				break;
			case 'P' :
			case 'p' :
				Puzzle_P( AP );
				break;
			case 'C' :
			case 'c' :
				Puzzle_C( AP );
				break;
			case 'Q' :
			case 'q' :
				T = TRUE;
				break;	
			default:
				Puzzle_Other( AP );
				break;
		}
		cout << endl;
	} while( !T );
}

/*
void main(void)
{
	Puzzle AP; 
	cout << "Puzzle test!" <<endl;
	InitPuzzle( AP );
	ExplanPuzzle( AP );
	DestoryPuzzle( AP );
}
*/
