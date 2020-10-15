#include<stdio.h>
#include<malloc.h>

typedef struct linkedList
{
    int val;
    struct linkedList *next;
}linkedList;


void main(){
    int i=0;
    int n=0;
    linkedList *p,*q,*head;
    p=(linkedList *)malloc(sizeof(linkedList));
    p->next = NULL;
    head=p;
    while(1){
        puts("input:");
        scanf("%d",&i);
        if(i==-1) break;
        q=(linkedList *)malloc(sizeof(linkedList));
        q->next=NULL;
        q->val=i;
        head->next=q;
        head = q;
    }
    
    while (p->next != NULL)
    {
        n++;
        p=p->next;
    }
    printf("%d\n",n);

}