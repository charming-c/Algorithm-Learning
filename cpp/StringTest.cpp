#include<iostream>
#include<string>
using namespace std;
bool IsAlphabet(char c){
    if(c>='a'&&c<='z' || c>='A'&& c<='Z')
    return true;
    else return false;
}
int main(){
    string text = "It was a Sunday. I never get up early on Sunday. I sometimes stay in bed until lunch time.";
    string word;
    string::iterator itr = text.begin();
    int pos1(0),pos2(0);
    int num(0);
    cout<<"input a word:"<<endl;
    getline(cin, word);
    while ((pos2 = text.find(word,pos1)) != string::npos)
    {
        if((pos2 == 0|| !IsAlphabet(itr[pos2-1])) && (pos2 +word.length() == text.length() || !IsAlphabet(itr[pos2+word.length()])))
        {
            num++;
            pos1 = pos2 + word.length();
        }
        else pos1++;
    }
    cout<<"Fine word \""<<word<<"\" "<<num<<" times"<<endl;
    return 0;
}