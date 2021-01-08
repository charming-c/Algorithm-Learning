#include <iostream>

using namespace std;

class Clock{
    private:
    int hour;
    int minute;
    int second;

    int Ahour;
    int Aminute;
    int Asecond;
    public:
    Clock(int h, int m,int s){
        hour = (h>23?0:h);
        minute = (m>59?0:m);
        second = (s>59?0:s);
    }
    void SetAlarm(int h, int m, int s){
        Ahour = (h>23?0:h);
        Aminute = (m>59?0:m);
        Asecond = (s>59?0:s);
    }
    void ShowTime(){
        cout<<"Now: "<<hour<<":"<<minute<<":"<<second<<endl;
    }
    void run(){
        second = second + 1;
        if(second > 59){
            second = 0;
            minute = minute +1;
        }
        if(minute >59){
            minute = 0;
            hour = hour+1;
        }
        if(hour>23) hour = 0;
        if(hour == Ahour && minute == Aminute && second == Asecond){
            cout<<"Plink!!!......"<<endl;
        }
    }
};
int main(){
    Clock D1(7,59,57);
    D1.SetAlarm(8,0,0);
    D1.ShowTime();
    for(int i = 0; i<3600*24+100;i++)
        D1.run();
        D1.ShowTime();
        return 0;
}