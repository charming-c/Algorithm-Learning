#include<stdio.h>
#include<stdlib.h>

void create_Next(char parrtern[],int next[], int n){
    next[0] = 0;
    int i = 1;
    while( i < n) {
        int temp = next[i-1];
        while (temp != 0 && parrtern[i] != parrtern[temp]) 
        {
            temp = next[temp-1];
        }
        if(parrtern[i] == parrtern[temp]) {
            next[i] = temp+1;
        }
        else next[i] = 0;
        i++;
    }
}

void move_Next(int next[], int n){
    int i = n-1;
    while (i > 0)
    {
        next[i] = next[i-1];
        i--;
    }
    next[0] = -1;
    // for(int i = 0; i<n; i++){
    //     printf("%d\n", next[i]);
    // }
}

void kmp_search(char s[], char t[], int next[], int m, int n){
    int i = 0; 
    int j = 0;
    while(i < m){
        if(s[i] == t[j]){
            if(j == n-1){
                printf("I Found!!! At %d.\n",i-j);
                j = next[j];
            }
            else{
                i++;
                j++;
            }
        }
        else{
            j = next[j];
            if(j == -1){
                i++;
                j++;
            }
        }
    }
    if(i == m-1)
    printf("Not Found!!!");
}

int main(){
    char subString[12] = {'A','B','A','B','A','B','C','A','B','A','A','B'};
    char parrtern[9] =   {'A','B','A','B','C','A','B','A','A'};
    int next[9] = {0};
    create_Next(parrtern,next,9);
    move_Next(next,9);
    kmp_search(subString,parrtern,next,12,9);
    return 0;
}