#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// 将每一个学生以这样的节点存放到链表里
typedef struct Person{
    long    num;    		//学号
	char	name[20];		//姓名
	int	    age;		    //年龄
	int	    classno;	    //班级
	float	Math;			//数学
	float	C_Language;		//C语言
	float	English;		//英语
    struct Person* next;
}student;

int menu(void){
    int i;
	system("title 学生成绩管理系统  By蔡加明");
	printf("\n\n");
	printf("\t\t\t    学生成绩管理系统  by蔡加明\n");
	printf("\t\t\t             菜单栏                                         \n");
	printf("\t\t\t1.  输入成绩                                                \n");
	printf("\t\t\t2.  计算每门课的平均成绩和总成绩                                    \n");
	printf("\t\t\t3.  计算每位同学的平均成绩和总成绩                                   \n");
	printf("\t\t\t4.  按总成绩排序                                            \n");
	printf("\t\t\t5.  单门科目成绩排名                                         \n");
	printf("\t\t\t6.  通过学号排序                                            \n");
	printf("\t\t\t7.  通过姓名首字母排序                                   \n");
	printf("\t\t\t8.  通过学号查成绩                                           \n");
	printf("\t\t\t9.  通过姓名查成绩                                           \n");
	printf("\t\t\t10. 打印成绩信息                                             \n");
	printf("\t\t\t11. 写入文件                                                 \n");
	printf("\t\t\t12. 读取文件                                                 \n");
	printf("\t\t\t0.  退出                                                    \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t输入选项:");
	scanf("%d", &i);
	return i;
}

// 将链表内容保存到文件里
void saveFile(char text[20],student* head){
    FILE * fp;
    student *cursor=head->next;
    fp=fopen(text,"w");
    if(fp==NULL){
        printf("file wasn't open!");
        exit(1);
    }
    while(cursor!=NULL){
        fprintf(fp,"\t\t\t%8ld  %4s   %2d   %d    %3.2f  %3.2f  %3.2f\n",cursor->num,cursor->name,cursor->age,cursor->classno,cursor->Math,cursor->C_Language,cursor->English);
        cursor=cursor->next;
    }
    printf("\t\t\t保存成功！\n");
    fclose(fp);
    fflush(stdin);
}

// 打印整个链表成绩信息
void printfMessage(student *head,int n){
    student *p=head->next;
    puts("\t\t\t    学号  姓名  年龄  班号   数学  C语言  英语");
    while(p!=NULL){
        printf("\t\t\t%8ld  %4s   %2d   %d    %3.2f  %3.2f  %3.2f\n",p->num,p->name,p->age,p->classno,p->Math,p->C_Language,p->English);
        p=p->next;
    }
    saveFile("grade",head);
}

// 打印一个学生的成绩
void print(student *p){

    puts("\t\t\t    学号  姓名  年龄  班号   数学  C语言  英语");
    printf("\t\t\t%8ld  %4s   %2d   %d    %3.2f  %3.2f  %3.2f\n",p->num,p->name,p->age,p->classno,p->Math,p->C_Language,p->English);

}

// 通过姓名查成绩
void searchbyName(student *head, int n,char name[]){
    student *p=head->next;
    student *node=head->next;

    int flag=0;

    if(node==NULL){
        printf("\t\t\t内容为空白，请先输入成绩，或读取文件信息。\n\n");
        return;
    }
    while(p!=NULL){
        if(!strcmp(name,p->name)){
            print(p);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0){
        printf("\t\t\t没有姓名匹配的学生！\n");
    }
}


// 通过学号查找成绩
void searchbyNum(student *head, int n,long num){
    student *p=head->next;
    student *node=head->next;

    int flag=0;
    if(node==NULL){
        printf("\t\t\t内容为空白，请先输入成绩，或读取文件信息。\n\n");
        return;
    }
    while(p!=NULL){
        if(num==p->num){
            print(p);
            flag=1;
        }
        p=p->next;
    }
    if(flag==0){
        printf("\t\t\t没有匹配的学号！\n");
    }
}

// 交换两个学生的信息(供排序使用)
void change(student *first,student *second){
        long    num;    		
	    char	name[20];		
	    int	    age;		    
	    int	    classno;	    
	    float	Math;			
	    float	C_Language;		
	    float	English;

        num=first->num;		
        first->num=second->num;
        second->num=num;

        strcpy(name,first->name);
        strcpy(first->name,second->name);
        strcpy(second->name,name);

        age=first->age;
        first->age=second->age;
        second->age=age;

        classno=first->classno;
        first->classno=second->classno;
        second->classno=classno;

        Math=first->Math;
        first->Math=second->Math;
        second->Math=Math;

        C_Language=first->C_Language;
        first->C_Language=second->C_Language;
        second->C_Language=C_Language;

        English=first->English;
        first->English=second->English;
        second->English=English;
}

// 按姓名首字母排
void sortbyName(student *head, int n){
    student *cursor=head;
    student *node=head->next;
    char c1;
    char c2;
    if(node==NULL){
        printf("\t\t\t内容为空白，请先输入成绩，或读取文件信息。\n\n");
        return;
    }
    
    while(cursor->next!=NULL){
        while(node->next!=NULL){
            student *firstNode=node;
            student *secondNode=node->next;
            c1=firstNode->name[0];
            c2=secondNode->name[0];

            if(c1>c2){
                change(firstNode,secondNode);
            }
        node=node->next;
        }
        node=head->next;
        cursor=cursor->next;
    }

    cursor->next=NULL;
    printfMessage(head,n);
}

// 按学号排
void sortbyNum(student *head,int n){
    student *cursor=head;
    student *node=head->next;
    long num1=0;
    long num2=0;

    if(node==NULL){
        printf("\t\t\t内容为空白，请先输入成绩，或读取文件信息。\n\n");
        return;
    }
    
    while(cursor->next!=NULL){
        while(node->next!=NULL){
            student *firstNode=node;
            student *secondNode=node->next;
            num1=(firstNode->num);
            num2=(secondNode->num);

            if(num1>num2){
                change(firstNode,secondNode);
            }
        node=node->next;
        }
        node=head->next;
        cursor=cursor->next;
    }

    cursor->next=NULL;
    printfMessage(head,n);
}

// 按数学成绩排
void sortbyMath(student *head,int n){
    student *cursor=head;
    student *node=head->next;
    float sum1=0.0;
    float sum2=0.0;
    if(node==NULL){
        printf("\t\t\t内容为空白，请先输入成绩，或读取文件信息。\n\n");
        return;
    }
    
    while(cursor->next!=NULL){
        while(node->next!=NULL){
            student *firstNode=node;
            student *secondNode=node->next;
            sum1=(firstNode->Math);
            sum2=(secondNode->Math);

            if(sum1<sum2){
                change(firstNode,secondNode);
            }
        node=node->next;
        }
        node=head->next;
        cursor=cursor->next;
    }

    cursor->next=NULL;
    printfMessage(head,n);
    
}
// 按c语言成绩排
void sortbyC(student *head,int n){
    student *cursor=head;
    student *node=head->next;
    float sum1=0.0;
    float sum2=0.0;
    if(node==NULL){
        printf("\t\t\t内容为空白，请先输入成绩，或读取文件信息。\n\n");
        return;
    }
    
    while(cursor->next!=NULL){
        while(node->next!=NULL){
            student *firstNode=node;
            student *secondNode=node->next;
            sum1=(firstNode->C_Language);
            sum2=(secondNode->C_Language);

            if(sum1<sum2){
                change(firstNode,secondNode);
            }
        node=node->next;
        }
        node=head->next;
        cursor=cursor->next;
    }
    cursor->next=NULL;
    printfMessage(head,n);
    
}

// 按英语成绩排
void sortbyEnglish(student *head,int n){
    student *cursor=head;
    student *node=head->next;
    float sum1=0.0;
    float sum2=0.0;
    if(node==NULL){
        printf("\t\t\t内容为空白，请先输入成绩，或读取文件信息。\n\n");
        return;
    }
    
    while(cursor->next!=NULL){
        while(node->next!=NULL){
            student *firstNode=node;
            student *secondNode=node->next;
            sum1=(firstNode->English);
            sum2=(secondNode->English);

            if(sum1<sum2){
                change(firstNode,secondNode);
            }
        node=node->next;
        }
        node=head->next;
        cursor=cursor->next;
    }
    cursor->next=NULL;
    printfMessage(head,n);
    
}

// 按科目排名
void sortbyCourse(student* head,int n){
    int choice;
    while(1){
        puts("\t\t\t按照以下哪门科目排序输出？");
        puts("\t\t\t1.数学");
        puts("\t\t\t2.C语言");
        puts("\t\t\t3.英语");
        puts("\t\t\t4.退出");
        printf("\t\t\t输入选项:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: sortbyMath(head,n);
            break;
        case 2: sortbyC(head,n);
            break;
        case 3: sortbyEnglish(head,n);
            break;
        case 4: return;
        default:
            break;
        }
    }

}

// 按总成绩给每位同学排序
void sortbyScore(student* head,int n){
    student *cursor=head;
    student *node=head->next;
    float sum1=0.0;
    float sum2=0.0;
    if(node==NULL){
        printf("\t\t\t内容为空白，请先输入成绩，或读取文件信息。\n\n");
        return;
    }
    
    while(cursor->next!=NULL){
        while(node->next!=NULL){
            student *firstNode=node;
            student *secondNode=node->next;
            sum1=(firstNode->Math)+(firstNode->C_Language)+(firstNode->English);
            sum2=(secondNode->Math)+(secondNode->C_Language)+(secondNode->English);

            if(sum1<sum2){
                change(firstNode,secondNode);
            }
        node=node->next;
        }
        node=head->next;
        cursor=cursor->next;
    }

    cursor->next=NULL;
    printfMessage(head,n);
    

}

// 计算每位同学的平均成绩和总成绩
void averageScore2(student* head,int n){

    float sum=0.0;
    student *p=head->next;
    for(int i=0;i<n;i++){
        sum=(p->Math)+(p->C_Language)+(p->English);
        printf("\t\t\t%s:  总分: %.1f   平均分：%.4f\n",p->name,sum,sum/3.0);
        p=p->next;
    }
}

// 计算每门课总成绩、平均成绩
void averageScore1(student* head,int n){
    float sum1=0.0;
    float sum2=0.0;
    float sum3=0.0;
    float x=(float)n;
    student *p=head->next;

    while(p!=NULL){
        sum1+=p->Math;
        sum2+=p->C_Language;
        sum3+=p->English;
        p=p->next;
    }

    printf("\n\n");
    printf("\t\t\t数学课  总成绩： %.1f            平均成绩：%.4f\n",sum1,sum1/x);
    printf("\t\t\tC语言课 总成绩： %.1f            平均成绩：%.4f\n",sum2,sum2/x);
    printf("\t\t\t英语课  总成绩： %.1f            平均成绩：%.4f\n",sum3,sum3/x);
}

// 创建链表,并且此时输入学生的成绩信息
void createList(student* head,int n){
    student *p,*q;
    q=head;
    q->next=NULL;

    for(int i=0;i<n;i++){
        long num;
        char name[20];
        int age,classno;
        float Math,C_Language,English;
        // p表示新创建节点
        p=(student*)malloc(sizeof(student));
        if(p==NULL) printf("\t\t\tmalloc fail!\n");

        memset(p,0,sizeof(student));

        p->next=NULL;
        // 填入信息
        printf("\t\t\t正在录入第%d个学生的信息：\n",i+1);

        printf("\t\t\t学号:");
        scanf("%ld",&num);
        p->num=num;

        printf("\t\t\t姓名:");
        scanf("%s",name);
        strcpy(p->name,name);

        printf("\t\t\t年龄:");
        scanf("%d",&age);
        p->age=age;

        printf("\t\t\t班号:");
        scanf("%d",&classno);
        p->classno=classno;

        printf("\t\t\t数学成绩:");
        scanf("%f",&Math);
        while(Math<0){
            printf("数据错误，请重新输入！\n");
            printf("\t\t\t数学成绩:");
            scanf("%f",&Math);
        }
        p->Math=Math;

        printf("\t\t\tC语言成绩:");
        scanf("%f",&C_Language);
        while(C_Language<0){
            printf("数据错误，请重新输入！\n");
            printf("\t\t\tC语言成绩:");
            scanf("%f",&C_Language);
        }
        p->C_Language=C_Language;

        printf("\t\t\t英语成绩:");
        scanf("%f",&English);
        while(English<0){
            printf("数据错误，请重新输入！\n");
            printf("\t\t\t英语成绩:");
            scanf("%f",&English);
        }
        p->English=English;
        // 将p节点加入到链表中
        q->next=p;
        // 尾节点后移一位
        q=q->next;
    }
    saveFile("grade",head);
}
int readFile(char text[20]){
    int count=0;
    int flag=1;
    FILE *fp;
    student *p;
    fp=fopen(text,"r");
    if(fp==NULL){
        printf("file wasn't open!");
        exit(1);
    }
    p=(student*)malloc(sizeof(student));
    
    memset(p,0,sizeof(student));

    while(fscanf(fp,"%ld  %s   %d   %d    %f  %f  %f\n",&p->num,p->name,&p->age,&p->classno,&p->Math,&p->C_Language,&p->English)!=EOF){
        printf("\t\t\t%8ld  %4s   %2d   %d    %3.2f  %3.2f  %3.2f\n",p->num,p->name,p->age,p->classno,p->Math,p->C_Language,p->English);
        count++;
    }
    fclose(fp);
    return count;
}

// 读取文件内容并创建链表
void createListbyFile(char text[20],student *head){
    student *p,*q;
    FILE *fp;
    q=head;
    q->next=NULL;
    p=(student*)malloc(sizeof(student));
    memset(p,0,sizeof(student));

    fp=fopen(text,"r");
    if(fp==NULL){
        printf("file wasn't open!");
        exit(1);
    }

    p->next=NULL;
    while(fscanf(fp,"%ld  %s   %d   %d    %f  %f  %f\n",&p->num,p->name,&p->age,&p->classno,&p->Math,&p->C_Language,&p->English)!=EOF){
        q->next=p;
        q=q->next;
        p=(student*)malloc(sizeof(student));
        memset(p,0,sizeof(student));

    }
    fclose(fp);
}

int main(){
    int chioce;
    int chioce2;
    char name[20];
    int n=0;
    student head;
    head.next=NULL;

    while(1){
        chioce=menu();
        switch(chioce){
            case 0: 
                printf("\t\t\t多谢使用，再见~~\n");
                exit(1);
            case 1:
                system("cls");
                printf("\t\t\t录入学生人数为：");
                scanf("%d",&n);
                while(n<=0){
                    printf("\t\t\t错误，请重新输入！");
                    scanf("%d",&n);
                }
                createList(&head,n);
                break;
            case 2:
            system("cls");
                averageScore1(&head,n);
                break;
            case 3:
                system("cls");
                averageScore2(&head,n);
                break;
            case 4:
                system("cls");
                sortbyScore(&head,n);
                break;
            case 5:
                system("cls");
                sortbyCourse(&head,n);
                break;
            case 6:
                system("cls");
                sortbyNum(&head,n);
                break;
            case 7:
                system("cls");
                sortbyName(&head,n);
                break;
            case 8:
                system("cls");
                printf("\t\t\t请输入学号：");
                scanf("%d",&chioce2);
                searchbyNum(&head,n,chioce2);
                break;
            case 9:
                system("cls");
                printf("\t\t\t请输入姓名：");
                scanf("%s",name);
                searchbyName(&head,n,name);
                break;

            case 10:
                system("cls");
                printfMessage(&head,n);
                break;

            case 11:
                saveFile("grade",&head);
                break;

            case 12:
                n=readFile("grade");
                if(head.next==NULL){
                    createListbyFile("grade",&head);
                }
                break;
            
            default: printf("\t\t\t请输入正确的选项！");
                    break;
        }
    }
}