#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<malloc.h>

#ifndef DLIST
#define TRUE  1
#define FALSE 0

struct Node{
    int data;
    struct Node *next;
};

// 在头文件将函数声明好
extern struct Node* ListCreat( int *a, int n);
extern void ListDestory(struct Node *L);
extern void ListShow(struct Node *L);
extern int ListSearch(struct Node *L, int x);
extern int ListLen(struct Node *L);
extern struct Node* ListPos(struct Node *L, int x);
extern void ListInsert(struct Node *L, int x,int pos);
extern int ListDelete(struct Node *L,int pos);


#endif 
