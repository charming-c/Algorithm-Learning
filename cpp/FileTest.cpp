#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int words(char * line){
    int words = 0;
    bool PreChar = false;
    bool CurChar = false;
    for(int i = 0; i<strlen(line); i++){
        if(line[i] >= 'A'&&line[i]<='Z' || line[i]>='a'&&line[i]<='z')
        CurChar = true;
        else CurChar = false;
    
    if(!PreChar&&CurChar)
    words++;
    PreChar = CurChar;
    }
    return words;
}
int main(){
    const int N = 1024;
    char line[N];
    int lines = 0, TotalWord = 0;
    char filename[40];
    ifstream txtfile;
    cout<<"text file:"<<endl;
    cin>>filename;
    txtfile.open(filename);
    if(!txtfile){
        cerr<<"File open Error!"<<endl;
        exit(1);
    }
    while (txtfile.getline(line,N))
    {
        TotalWord +=words(line);
        lines++;
    }
    txtfile.close();
    cout<<"total lines: "<<lines<<endl;
    cout<<"total words: "<<TotalWord<<endl;
    return 0;
}