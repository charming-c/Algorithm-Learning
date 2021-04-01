#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,j = 0;
    char subString[16] = {'A','B','A','B','A','B','C','A','B','A','B','C','A','B','A','A'};
    char parrtern[9] =   {'A','B','A','B','C','A','B','A','A'};
    for(int i  = 0; i<16; i++){
        int cursor = i;
        for(int j = 0; j<9; j++){
            if(subString[cursor] != parrtern[j]){
                break;
            }
            else{
                if(subString[cursor] == parrtern[j] && j == 8){
                    printf("I Found!!! At %d.\n",i);
                    break;
                }
                else cursor++;
            }
        }
    }
    return 0;
}