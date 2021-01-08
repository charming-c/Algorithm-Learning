#include<iostream>

using namespace std;

class Data{
    private:
    int year;
    int month;
    int day;
    public:
    Data(int y = 2001, int m = 4, int d = 9);
    int days(int year, int month);
    void NewDay();
    void display(){
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
};
Data::Data(int y, int m, int d){
    if(m>12||m<1){
        cout<<"Invalid Mmonth!!!"<<endl;
        month = 1;
    }
    if(d>days(y,m)){
        cout<<"Invalid Day!!!"<<endl;
        day = 1;
    }
    day = d;
    year = y;
    month = m;
}
int Data::days(int year, int month){
    bool leap;
    if((year % 400 == 0) || (year%4 == 0 && year %100 != 0)) leap = true;
    else leap = false;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if(leap == true) return 29;
        else return 28;
        break;
    }
    
}

void Data::NewDay(){
    if(day<days(year,month))
        day++;
    else{
        day = 1;
        month++;
        if(month >12){
            year++;
            month = 1;
        }
    }
}

int main(){
    Data data(2020,1,1);
    data.display();
    data.NewDay();
    data.display();
    return 0;
}