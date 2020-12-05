// c1.h (������)

#ifndef C_H
#define C_H

#include<string.h>
#include<ctype.h>
#include<malloc.h> // malloc()��
#include<limits.h> // INT_MAX��
#include<stdio.h> // EOF(=^Z��F6),NULL
#include<stdlib.h> // atoi()
#include<io.h> // eof()
#include<math.h> // floor(),ceil(),abs()
#include<process.h> // exit()
#include<iostream> // cout,cin

#define TRUE		1
#define FALSE		0
#define OK			1
#define ERROR		0
#define INFEASIBLE -1
#define MAX_LENGTH   100

typedef int Bool;
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
//typedef int ElemType;
typedef char ElemType; 

#endif