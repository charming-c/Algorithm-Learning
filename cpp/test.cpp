#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class CGraph
{
protected:
    char content[100];
    int line;

public:
    CGraph(char *content, int line = 1)
    {
        strcpy(this->content, content);
        this->line = line;
    }
    virtual string getData() = 0;
    virtual char *getType() = 0;
    virtual void show() = 0;
    virtual ~CGraph()
    {
        this->line = 0;
    }
};

class CRect : virtual public CGraph
{
protected:
    int startPos[2];
    int endPos[2];
    int length;
    int width;

public:
    CRect(char *content, int startPos[], int endPos[], int line) : CGraph(content, line)
    {
        this->startPos[0] = startPos[0];
        this->startPos[1] = startPos[1];
        this->endPos[0] = endPos[0];
        this->endPos[1] = endPos[1];
        this->length = endPos[0] - startPos[0];
        this->width = endPos[1] - startPos[1];
    }
    char *getType()
    {
        static char type[] = "CRect";
        return type;
    }
    string getData()
    {
        stringstream ss1;
        string str;
        ss1 << startPos[0];
        ss1 >> str;
        string data1 = "startPosition:(" + str + ",";
        stringstream ss2;
        ss2 << startPos[1];
        ss2 >> str;
        string data2 = data1 + str + ")" + "\n";
        stringstream ss3;
        ss3 << endPos[0];
        ss3 >> str;
        string data3 = data2 + "endPosition:(" + str + ",";
        stringstream ss4;
        ss4 << endPos[1];
        ss4 >> str;
        string data4 = data3 + str + ")" + "\n";
        stringstream ss5;
        ss5 << length;
        ss5 >> str;
        string data5 = data4 + "length:" + str + "\n";
        stringstream ss6;
        ss6 << width;
        ss6 >> str;
        string data6 = data5 + "width:" + str + "\n";
        string str2(content);
        string data = data6 + "content:" + str2;
        return data;
    }
    void show()
    {
        cout << "CRect:" << endl;
        cout << "startPosition:"
             << "(" << startPos[0] << "," << startPos[1] << ")" << endl;
        cout << "endPosition:"
             << "(" << endPos[0] << "," << endPos[1] << ")" << endl;
        cout << "length:" << length << "\t"
             << "width:" << width << endl;
        cout << "content:" << content << endl;
        cout << "lineWidth:" << line << endl;
    }
    ~CRect()
    {
        length = width = 0;
        startPos[0] = startPos[1] = endPos[0] = endPos[1] = 0;
    }
};

class CEllipse : virtual public CGraph
{
protected:
    int LRadius;
    int SRadius;

public:
    CEllipse(char *content, int LRadius, int SRadius, int line = 1) : CGraph(content, line)
    {
        this->LRadius = LRadius;
        this->SRadius = SRadius;
    }
    char *getType()
    {
        static char type[] = "CEllipse";
        return type;
    }
    string getData()
    {
        stringstream ss1;
        string str;
        ss1 << LRadius;
        ss1 >> str;
        string data1 = "LRadius:" + str + "\n";
        stringstream ss2;
        ss2 << SRadius;
        ss2 >> str;
        string data2 = data1 + "SRadius:" + str + "\n";
        string str2(content);
        stringstream ss3;
        ss3 << line;
        ss3 >> str;
        string data3 = data2 + "lineWidth:" + str + "\n";
        string data = data3 + "content:" + str2;
        return data;
    }
    void show()
    {
        cout << "CEllipse:" << endl;
        cout << "LRadius:" << LRadius << endl;
        cout << "SRadius:" << SRadius << endl;
        cout << "content:" << content << endl;
        cout << "lineWidth:" << line << endl;
    }
    ~CEllipse()
    {
        LRadius = 0;
        SRadius = 0;
    }
};

class CRoundCRect : public CRect, public CEllipse
{
protected:
    int radius;

public:
    CRoundCRect(char *content, int startPos[], int endPos[], int LRadius, int SRadius, int radius, int line) : CGraph(content, line), CRect(content, startPos, endPos, line), CEllipse(content, LRadius, SRadius, line)
    {
        this->radius = radius;
    }
    char *getType()
    {
        static char type[] = "CRoundCRect";
        return type;
    }
    string getData()
    {
        stringstream ss1;
        string str;
        ss1 << startPos[0];
        ss1 >> str;
        string data1 = "startPosition:(" + str + ",";
        stringstream ss2;
        ss2 << startPos[1];
        ss2 >> str;
        string data2 = data1 + str + ")" + "\n";
        stringstream ss3;
        ss3 << endPos[0];
        ss3 >> str;
        string data3 = data2 + "endPosition:(" + str + ",";
        stringstream ss4;
        ss4 << endPos[1];
        ss4 >> str;
        string data4 = data3 + str + ")" + "\n";
        stringstream ss5;
        ss5 << length;
        ss5 >> str;
        string data5 = data4 + "length:" + str + "\n";
        stringstream ss6;
        ss6 << width;
        ss6 >> str;
        string data6 = data5 + "width:" + str + "\n";
        string str2(content);
        string data7 = data6 + "content:" + str2 + "\n";
        stringstream ss7;
        ss7 << LRadius;
        ss7 >> str;
        string data8 = data7 + "LRadius:" + str + "\n";
        stringstream ss8;
        ss8 << SRadius;
        ss8 >> str;
        string data9 = data8 + "SRadius:" + str + "\n";
        stringstream ss9;
        ss9 << line;
        ss9 >> str;
        string data10 = data9 + "lineWidth:" + str + "\n";
        string data = data10;
        return data;
    }
    void show()
    {
        cout << "CRoundRect:" << endl;
        cout << "startPosition:"
             << "(" << startPos[0] << "," << startPos[1] << ")" << endl;
        cout << "endPosition:"
             << "(" << endPos[0] << "," << endPos[1] << ")" << endl;
        cout << "length:" << length << "\t"
             << "width:" << width << endl;
        cout << "LRadius:" << LRadius << endl;
        cout << "SRadius:" << SRadius << endl;
        cout << "radius:" << radius << endl;
        cout << "content:" << content << endl;
        cout << "lineWidth:" << line << endl;
    }
    ~CRoundCRect()
    {
        this->radius = 0;
    }
};

class CPPage
{
private:
    CGraph **p;
    int number;

public:
    CPPage()
    {
        int choice = 0;
        int startPos[2];
        int endPos[2];
        int LRadius;
        int SRaduis;
        int radius;
        int line;
        char content[100];
        int n = 0;
        cout << "how many graphs do you want to create? ";
        cin >> n;
        this->number = n;
        p = new CGraph *[n];
        for (int i = 0; i < n; i++)
        {
            cout << "No." << i + 1 << ":" << endl;
            cout << "your choice:" << endl;
            cout << "1-CRect"
                 << "\t"
                 << "2-CEllipse"
                 << "\t"
                 << "3-CRoundRect" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "startPos:";
                cin >> startPos[0];
                cin >> startPos[1];
                cout << "endPos:";
                cin >> endPos[0];
                cin >> endPos[1];
                cout << "content:";
                cin >> content;
                cout << "line:";
                cin >> line;
                p[i] = new CRect(content, startPos, endPos, line);
                break;
            case 2:
                cout << "LRadius:";
                cin >> LRadius;
                cout << "SRadius:";
                cin >> SRaduis;
                cout << "content:";
                cin >> content;
                cout << "line:";
                cin >> line;
                p[i] = new CEllipse(content, LRadius, SRaduis, line);
                break;
            case 3:
                cout << "startPos:";
                cin >> startPos[0];
                cin >> startPos[1];
                cout << "endPos:";
                cin >> endPos[0];
                cin >> endPos[1];
                cout << "content:";
                cin >> content;
                cout << "line:";
                cin >> line;
                cout << "LRadius:";
                cin >> LRadius;
                cout << "SRadius:";
                cin >> SRaduis;
                cout << "radius:";
                cin >> radius;
                p[i] = new CRoundCRect(content, startPos, endPos, LRadius, SRaduis, radius, line);
                break;
            default:
                i--;
                break;
            }
        }
    }
    void showPage()
    {
        for (int i = 0; i < number; i++)
        {
            p[i]->show();
            cout << endl;
        }
    }
    CGraph **getCGraph()
    {
        return p;
    }
    int getNum()
    {
        return number;
    }
    ~CPPage()
    {
        for (int i = 0; i < number; i++)
            delete p[i];
        delete p;
        number = 0;
    }
};

int main()
{
    vector<CPPage> pageVector;
    int random = 1;
    int num = 0;
    while (1)
    {
        cout << "do you want to create a page? " << endl;
        cout << "1-Yes"
             << "\t"
             << "0-No" << endl;
        cin >> random;
        if (random == 0)
            break;
        CPPage *cp = new CPPage();
        pageVector.push_back(*cp);
        cout << "do you want to write in file?" << endl;
        cout << "1-Yes"
             << "\t"
             << "0-No" << endl;
        cin >> num;
        if (num == 1)
        {
            fstream textfile;
            textfile.open("temp.txt", ios::in | ios::out);
            if (!textfile)
            {
                cerr << " temp.txt open error!!!" << endl;
                exit(1);
            }
            else
            {
                CGraph **p = cp->getCGraph();
                int num2 = cp->getNum();
                textfile << "CPPage:" << endl;
                for (int i = 0; i < num2; i++)
                {
                    textfile << p[i]->getType() << ":" << endl;
                    textfile << p[i]->getData() << endl;
                }
                textfile.close();
            }
            cout << "do you want to read the file?" << endl;
            cout << "1-Yes"
                 << "\t"
                 << "0-No" << endl;
            int num3;
            cin >> num3;
            if (num3 == 1)
            {
                fstream file;
                file.open("temp.txt", ios::in | ios::out);
                string s;
                while (getline(file, s))
                {
                    cout << s << endl;
                }
                file.close();
            }
        }
    }
    cout << "you have created " << pageVector.size() << " CPPages" << endl;
    while (1)
    {
        cout << "you can choose one to show" << endl;
        int count;
        for (int i = 0; i < pageVector.size(); i++)
        {
            cout << "page " << i << endl;
        }
        cin >> count;
        vector<CPPage>::iterator it = pageVector.begin();
        if (count > pageVector.size())
            cout << "no such page" << endl;
        else
            it[count].showPage();
        cout << "coutine?" << endl;
        cout << "1-Yes"
             << "\t"
             << "0-No" << endl;
        int count2;
        cin >> count2;

        if (count2 == 0)
            break;
    }
    for (int i = 0; i < pageVector.size(); i++)
    {
        pageVector.pop_back();
    }
    return 0;
}