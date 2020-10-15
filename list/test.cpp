#include"DList.h"

int main(){
    struct Node *L;
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    L = ListCreat(a,10);
    ListShow(L);
    return 0;
}