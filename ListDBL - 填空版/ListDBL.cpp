#include "ListDBL.h"

void InitList( struct List &L )
{
	struct ListNode* node;
	node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = NULL;
	node->prior = node;
	node->next = node;
	L.CurPos = node;
	L.StartPos = node;
	L.EndPos = node;
	L.Length = 0;
}

void DestroyList( List &L )
{
	int n = L.Length;
	ListNode *node;
	while(L.Length!=0){
		node = L.StartPos;
		L.StartPos = L.StartPos->next;
		free(node);
		L.Length--;
	}
	InitList(L);
}

void insert( List &L, ElemType &newData )  
{
	struct ListNode *p;
	struct ListNode *node1,*node2;
	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1 = L.CurPos;
	p->data = newData;
	node2 = node1->next;
	p->next = node2;
	p->prior = node1;
	node1->next = p;
	node2->prior = p;

	if(L.EndPos == L.CurPos){
		L.EndPos = L.EndPos->next;
	}
	L.CurPos = p;
	L.Length++;
	if(L.Length == 1){
		L.StartPos = p;
	}
}


int remove( List &L ) 
{
	if(L.Length == 0){
		return 0;
	}
	ListNode *node1 = L.CurPos->prior;
	ListNode *node2 = L.CurPos->next;
	free(L.CurPos);
	L.CurPos = node1;
	node1->next = node2;
	node2->prior = node1;
	L.Length--;
	return 1;
}

void replace( List &L, ElemType &newDataItem )
{	
	if(isEmpty(L) == TRUE){
		printf("the Link is Empty!");
		return;
}
	L.CurPos->data = newDataItem;
}

void clear( List &L ) 							  
{
	DestroyList(L);
}


bool isEmpty(List L) 						
{
	if(L.Length == 0){
		return TRUE;
	}else
	{
		return FALSE;
	}
	
}


bool isFull(List L) 						
{
	if(L.Length == MAX_LENGTH){
		return TRUE;
	}else
	{
		return FALSE;
	}
	
}


void gotoBeginning(List &L) 				
{
	while(L.CurPos != L.StartPos){
		L.CurPos = L.CurPos->prior;
	}
}


void gotoEnd(List &L) 					
{
	while(L.CurPos != L.EndPos){
		L.CurPos = L.CurPos->next;
	}
}


bool gotoNext(List &L) 
{
	if(L.CurPos == L.EndPos){
		L.CurPos = L.StartPos;
	}else
	{
		L.CurPos = L.CurPos->next;
	}
	return TRUE;
}
					
bool gotoPrior(List &L) 
{
	if(isEmpty(L) == TRUE){
		printf("The List is empty!");
		return FALSE;
	}
	if(L.CurPos == L.StartPos){
		L.CurPos = L.EndPos;
	}
	else
	{
		L.CurPos = L.CurPos->prior;
	}
	return TRUE;
}

					
ElemType getCursor(List L)					
{
	if(L.CurPos != NULL){
		return L.CurPos->data;
	}
	else return NULL;
}


void showStructure(List L)
{
	ListNode *p;
	if(L.Length == NULL){
		printf("Empty List!");
	}else
	{
		p = L.StartPos;
		for(int i= 0; i<L.Length; i++){
			printf("%c",p->data);
			p = p->next;
		}
	}
	
}

int  getLength( List L )
{
	return L.Length;
}

int  getCurPosition( List L )
{
	int pos = 1;
	ListNode *p;
	if(L.Length == 0){
		return 0;
	}
	p = L.StartPos;
	while(p != L.CurPos){
		p = p->next;
		pos++;
	}
	return pos;
}
 
void Shift_R( List &L )
{

}

void Shift_L( List &L )
{
}

void Reverse( List &L )
{
	List *L2 = new List();
	ListNode *node,*node1;
	node1 = L.EndPos;
	L2->StartPos = L.EndPos;
	L2->CurPos = L.CurPos;
	node = L2->StartPos;
	node->next = node;
	node->prior = node;
	while(node1 != L.StartPos){
		insert(*L2,node1->data);
	}
	L = *L2;
}

void SwapItem( List &L )
{
}

void showListData( List &L )
{
	showStructure(L);
}

bool isEnd( List L )
{
	if(L.Length == 0){
		return TRUE;
	}
	if(L.CurPos == L.StartPos){
		return TRUE;
	}else
	return FALSE;
} 	
					
bool isHead( List L )
{
	if(L.Length == 0){
		return TRUE;
	}
	if(L.CurPos == L.StartPos){
		return TRUE;
	}else
	return FALSE;
} 						

void CreatList( List &L, char str[] )
{
	int len = sizeof(str)/sizeof((str)[0]);
	ListNode *p,*q;
	InitList(L);
	q = L.CurPos;
	for(int i = 0; i < len; i++){
		p = new ListNode();
		p->data = str[i];
		p->next = q->next;
		q->next = p;
		p->prior = q;
		q = q->next;
	}
	L.CurPos = L.CurPos->next;
	L.StartPos = L.CurPos;
	L.EndPos = p;
}

void ReplaceList( List &L, char str[] )
{
	InitList(L);
	// int len = sizeof(str)/sizeof((str)[0]);
	CreatList(L,str);
}

