#include "c1.h"
 
#ifndef LISTDBL_H
#define LISTDBL_H

struct ListNode {
	ElemType data;	
	ListNode  *prior, *next;
};

struct List {
	ListNode *StartPos;	
	ListNode *EndPos;
	ListNode *CurPos;
	int 	  Length;		
};


//传入的L是一个List的实例，也表示我们创建的链表
void InitList( List &L );
void DestroyList( List &L ); 	
void insert( List &L, ElemType &newData );  
int  remove( List &L ); 
void clear( List &L ); 							  
bool isEmpty( List L ); 						
bool isFull( List L ); 						
bool isEnd( List L ); 						
bool isHead( List L ); 						
void gotoBeginning( List &L ); 				
void gotoEnd( List &L ); 					
bool gotoNext( List &L ); 					
bool gotoPrior( List &L ); 					
ElemType getCursor(List L );					
void showStructure( List L );
void replace( List &L, ElemType &newDataItem );

int  getLength( List L );
int  getCurPosition( List L ); 
void Shift_R( List &L );
void Shift_L( List &L );
void SwapItem( List &L );
void Reverse( List &L );
void showListData( List &L );
void CreatList( List &L, char str[] );
void ReplaceList( List &L, char str[] );

#endif