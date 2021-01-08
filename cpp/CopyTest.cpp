#include<iostream>
#include<fstream>

using namespace std;

int main(){
    char buff[1024];
    char source1[80],source2[80],target[80];
    long bytes;
    ifstream infile1,infile2;
    ofstream outfile;
    cout<<"source file1"<<endl;
    cin>>source1;
    cout<<"source file2"<<endl;
    cin>>source2;
    cout<<"target file"<<endl;
    cin>>target;
    infile1.open(source1,ios::binary);
    infile2.open(source2,ios::binary);
    outfile.open(target,ios::binary| ios::out|ios::trunc);
    if(!outfile){
        cerr<<"File create error!"<<endl;
        exit(1);
    }
    if(infile1){
        infile1.seekg(0,ios::end);
        bytes = infile1.tellg();
        infile1.seekg(0,ios::beg);
        infile1.read(buff,bytes%1024);
        outfile.write(buff,bytes%1024);
        while(infile1.read(buff,1024))
        outfile.write(buff,1024);
        infile1.close();
    }
    if(infile2){
        infile2.seekg(0,ios::end);
        bytes = infile2.tellg();
        infile2.read(buff,bytes%1024);
        outfile.write(buff,bytes%1024);
        while(infile2.read(buff,1024))
        outfile.write(buff,1024);
        infile2.close();
    }
    outfile.close();
    return 0;
}