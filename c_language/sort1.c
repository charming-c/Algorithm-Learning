#include<stdio.h>
#include<malloc.h>

// 快速排序
void sort1(int *a,int n){
    int pivot=a[0];
    int flag=0;
    int left=0;
    int right=n;
    if(n==1|| n==0) return;
    while(left!=right){
        if(flag==0){
            if(a[right]<pivot){
                a[left]=a[right];
                left++;
                flag=1;
            }
            else right--;
        }
        else
        {
            if(a[left]>pivot){
                a[right]=a[left];
                right--;
                flag=0;
            }
            else left++;
        }
    }
        a[right]=pivot;
        sort1(a,left);
        sort1(a+left+1,n-left-1);
        
}
// 插入排序
void sort2(int *a,int n){
    int temp;
    for(int i=1;i<n;i++){
        temp=a[i];
         printf(" %d",a[i]);
        for(int j=i-1;j>=0;j--){
            if(temp<a[j]){
                a[j+1]=a[j];
            }
            if(temp>=a[j]){
                a[j+1]=temp;
            }
            if(j==0)
            a[j]=temp;
        }
    }
}


int main(){
    int a[10]={9,8,7,6,5,4,3,2,1,0};
    int n=8;
    // sort1(a,n);
    // sort2(a,n);
    int *x;
    // int a[4]={2,4,8,9};
    int b[4]={1,5,7,10};
    x=sort3_2(a,5,a+5,5,x);
    for(int i=0;i<n;i++){
            printf(" %d",x[i]);
        }
}