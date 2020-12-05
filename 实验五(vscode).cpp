#include <iostream>
#include <string.h>

using namespace std;

class CRect{
private:
	int startPos[2];
	int endPos[2];
	char *content;
	int width,length;

public:
	//这个是矩形类的空的构造器
	CRect(){
		startPos[0] = endPos[0] = 0;
		startPos[1] = endPos[1] = 0;
		width = length = 0;
		content = NULL;
	}

	//这里是传入位置参数和具体内容的构造器
	//考虑到有可能长度宽度的计算有可能为负数，这里用绝对值函数
	CRect(int start[], int end[], char *c){
		startPos[0] = start[0];
		startPos[1] = start[1];
		endPos[0] = end[0];
		endPos[1] = end[1];
		length = abs(end[0] - start[0]);
		width = abs(end[1] - start[1]);
		content = new char[strlen(c)+1];
		strcpy(content,c);
	}

	//这是拷贝构造函数，由于有指针的存在，我们采用深拷贝防止出现重复释放同一段空间的问题
	CRect(CRect &c){
		startPos[0] = c.startPos[0];
		startPos[1] = c.startPos[1];
		endPos[0] = c.endPos[0];
		endPos[1] = c.endPos[1];
		width = c.width;
		length = c.length;
		content = new char[strlen(c.content)+1];
		strcpy(content,c.content);
	}

	//这个方法打印矩形类对象所有信息
	void showCRect(){
		//cout<<"CRect:"<<endl;
		cout<<"start:"<<"	["<<startPos[0]<<","<<startPos[1]<<"]"<<endl;
		cout<<"end:"<<"	["<<endPos[0]<<","<<endPos[1]<<"]"<<endl;
		cout<<"width:	"<<width<<endl;
		cout<<"length:	"<<length<<endl;
		if(content!=NULL)
		cout<<"content:"<<content<<endl;
		else cout<<"content:"<<"null"<<endl;
	}

	//这是析构函数，主要是用来释放指针空间
	~CRect(){
		if(content != NULL){
			delete[] content;
			content = NULL;
		}
		width = 0;
		length = 0;
		startPos[0] = endPos[0] = 0;
		startPos[1] = endPos[1] = 0;
	}
	friend class CPPage;
    //声明友元类，方面后用来改私有变量
};

class CPPage{
private:
	int CountCRect;
	static int Counts;
	CRect *C;
public:
	//静态方法，获得静态数据
	static int getCounts(){
		return Counts;
	}
	//页面类的构造器，主要用来构造这里的矩形类数组的具体对象
	CPPage(int n){
		++Counts;
		CountCRect = n;
		C = new CRect[n];
		for(int i = 0; i<n; i++){
			cout<<"please input the start position:"<<endl;
			cin>>C[i].startPos[0]>>C[i].startPos[1];
			cout<<"please input the end position:"<<endl;
			cin>>C[i].endPos[0]>>C[i].endPos[1];
			C[i].content = new char[100];
            C[i].width = abs(C[i].endPos[1] - C[i].startPos[1]);;
            C[i].length = abs(C[i].endPos[0] - C[i].startPos[0]);
            cout<<"please input the content:"<<endl;
			cin>>C[i].content;
		}
	}

	//打印信息
	void showPage(){
		cout<<"CRect number:"<<CountCRect<<endl;
		for(int i = 0; i<CountCRect; i++){
			cout<<"CRect"<<i<<":"<<endl;
			C[i].showCRect();
		}
	}

	~CPPage(){
		if(C != NULL){
			delete[] C;
			C = NULL;
		}
		CountCRect = 0;
	}

};

int CPPage::Counts = 0;

int main()
{
    //这里之前用来检测矩形类里的各个函数方法是否写得正确
	//CRect c1;
	//int start[2] = {3,4};
	//int end[2] = {1,2};
	//char string[] = "hello,world";
	//char *s = "hello,world";
	//CRect c2(start, end, s);
	//CRect c3(c2);
	//c1.showCRect();
	//c2.showCRect();
	//c3.showCRect();
	int n =1;
	int x;
    cout<<"create a page?    1-Yes  0-NO"<<endl;
	cin>>n;
    //利用一个循环，询问是否重复创建ppt界面
	while(n){
		cout<<"how many CRect do you want create in the page?"<<endl;
		cin>>x;
		CPPage page(x);
		cout<<"page "<<CPPage::getCounts()<<":"<<endl;
		page.showPage();
        cout<<"create a page?    1-Yes  0-NO"<<endl;
	    cin>>n;
	}
	return 0;
}

