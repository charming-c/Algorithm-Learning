#include"DList.h"

struct Node* ListCreat(int *a, int n){
    int i;
    struct Node *p,*q;
    struct Node *L;
    L = (struct Node *)malloc(sizeof(struct Node));
    if(!L){
        printf("alloc ERROR!\n");
        exit(0);
    }
    L->next = NULL;
    q = L;

    if(n<=0){
        printf("NULL!\n");
        return NULL;
    }
    for(i=0; i<n; i++){
        p = (struct Node*)malloc(sizeof(struct Node));
        if(!p){
            printf("alloc error!\n");
            exit(0);
        }
        // 给定一个指针可以这样创建数组
        p->data = a[i];
        p->next = NULL;
        q->next = p;
        q = q->next;
    }
    return L;
}
void ListDestory(struct Node *L){
    struct Node *p,*q;
    p = L;
    if(!L) return;
    while(L){
        q = L;
        L = L->next;
        free(q);
    }

}

void ListShow(struct Node *L){
    struct Node *p;
    p = L->next;
    while(p){
        printf("%3d",p->data);
        p = p->next;
    }
    
}

int ListSearch(struct Node *L, int x){
    int ord=0;
    struct Node *p;
    p = L->next;
    while(p){
        if(p->data != x){
            ord++;
            p = p->next;
        }
        else return ord;
    }
    free(p);
    return 0;
}
int ListLen(struct Node *L){
    int len;
    struct Node *p;
    p = L->next;
    while(p){
        p = p->next;
        len++;
    }
    return len;
}
struct Node* ListPos(struct Node *L, int x){

    struct Node *p;
    p = L->next;
    while(p){
        if(p->data != x){
            p = p->next;
        }
        else return p;
    }
    free(p);
    return NULL;
}
void ListInsert(struct Node *L,int x, int pos){
    int i;
    struct Node *p,*q;
    p = L->next;
    q = (struct Node*)malloc(sizeof(struct Node));
    if(!q){
        printf("alloc ERROR!\n");
        exit(0);
    }
    if(pos<0) return;
    if(pos == 0){
        q->data = x;
        q->next = p;
        L->next = q;
        return;
    }
    // 赋值成头
    p = L;
    for(i = 0; i<pos; i++){
        if(p->next == NULL){
        // 跳出循环
        break;
        // q->data = x;
        // q->next = p->next;
        // p->next = q;
        }
        else p = p->next;
    }
    q->data = x;
    q->next = p->next;
    p->next = q;
}
int ListDelete(struct Node *L, int pos){
    struct Node *p,*q;
    int i,n;
    n = ListLen(L);
    if(pos<=0 || pos>=n){
        return FALSE;
    }
    p = L;
    for(i=1;i<pos;i++){
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return TRUE;
}
int main(){
    struct Node *L;
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    L = ListCreat(a,10);
    ListShow(L);
    return 0;
}
