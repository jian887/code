#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include<windows.h>

using namespace std;
static int n=0;
/*
 *	1.输入某个学期某个年级某个专业的期末成绩
 *	2.根据输入计算学分绩
 *	3.按照奖学金的评定规则，输出各等奖学金的获奖名单
 */



class exam //-----------------------------------成绩类
{
public:
    float Math;
    float English;
    float Java;
    float C;
    float CountScore;//总成绩
};
class final:public exam
{
public:
    float zong(float Math,float Englishb,float Java,float C)
    {
        CountScore=Math+English+Java+C;
        return Math+English+Java+C;
    }
};
class student //---------------------------------学生类
{
public:
    float calculate();//奖学金计算
public:
    string name;	  //姓名
    string sno;	      //学号
    char sex[5];   	  //性别
    int money;        //奖学金数额
    float XueFenJi;  //学分绩
    final fianlexam;  //期末考试成绩

};

float student::calculate()//计算学分绩并返回学分绩的值
{
    XueFenJi=(fianlexam.Math*4+fianlexam.English*4+fianlexam.Java*4+fianlexam.C*3)/(4+4+4+3);
    if(XueFenJi>=908)
        money=3000;
    else if(XueFenJi>=85&&XueFenJi<90)
        money=1500;
    else if(XueFenJi>=80&&XueFenJi<85)
        money=750;
    return XueFenJi;;
}


class guanli
{
public:
    void print();//操作界面
    void init(student *stu);//初始化
    int goon();//继续操作
    void LuRu(student *stu);//录入
    void show(student *stu);//查看奖学金信息函数
    void find(student *stu);//查询个人奖学金
};

void guanli::print()   //操作界面
{
    cout<<"┃--------------------------------------┃"<<endl;
    cout<<"┃         │ 奖学金计算系统 │	       ┃"<<endl;
    cout<<"┃  ════════════■□■□════════════    ┃"<<endl;
    cout<<"┃*********  1. 录入学生信息 *********┃"<<endl;
    cout<<"┃*********  2. 查看奖学金信息 *********┃"<<endl;
    cout<<"┃*********  3. 查询个人奖学金 *********┃"<<endl;
    cout<<"┃*********  4. 退出           *********┃"<<endl;
    cout<<"┃------------------------------------  ┃"<<endl;
}
int guanli::goon()       //打印函数
{
    int a;
    cout<<"继续操作请按1，退出请按0"<<endl;
    cin>>a;
    return a;
}
void guanli::LuRu(student *stu)        //录入学生信息函数
{
    float a,b,c,d,i;
    cout<<"输入学生姓名，学号，性别"<<endl;
    cin>>stu[n].name>>stu[n].sno>>stu[n].sex;
    cout<<"请选择输入"<<stu[n].name<<"的成绩"<<endl;
    cout<<"请输入该生期末成绩--请按--数学 英语 Java C++ 的顺序输入，否则默认为0"<<endl;
    cin>>a>>b>>c>>d;
    stu[n].fianlexam.Math=a;
    stu[n].fianlexam.English=b;
    stu[n].fianlexam.Java=c;
    stu[n].fianlexam.C=d;
    ofstream p;
    p.open("G:\\基本信息.txt",ios::app);
    if(!p)
    {
        cout<<"打开失败"<<endl;
        //return 0;
    }
    p<<endl<<stu[n].name<<" "<<stu[n].sno<<" "<<stu[n].sex<<stu[n].fianlexam.Math<<" "<<stu[n].fianlexam.English<<" "<<stu[n].fianlexam.Java<<" "<<stu[n].fianlexam.C;
    n++;
}

void guanli::init(student *stu) //初始化学生信息函数
{
    ifstream p;//ifstream 是从硬盘读到内存
    int i;
    p.open("G:\\基本信息.txt");
    if(!p)
    {
        cout<<"打开失败"<<endl;
        //exit(0);
    }
    while(!p.eof())	 //eof() 如果读文件到达文件末尾，返回true
    {
        p>>stu[n].name>>stu[n].sno>>stu[n].sex>>stu[n].fianlexam.Math>>stu[n].fianlexam.English>>stu[n].fianlexam.Java>>stu[n].fianlexam.C;
        n++;
    }
    for(i=0; i<n; i++)
        stu[i].calculate();
    p.close();
}

void guanli::show(student *stu)     //查看奖学金信息函数
{
    int i;
    cout<<"姓名"<<" "<<"学分绩"<<"   "<<"奖学金/元"<<endl;
    for(i=0; i<n; i++)
    {
        stu[i].calculate();
        cout<<stu[i].name<<" "<<stu[i].XueFenJi<<" "<<stu[i].money<<endl;
    }
}
void guanli::find(student *stu)     //查看个人奖学金
{
    float b;
    cout<<"请输入所查询学生学号"<<endl;
    string sno;
    cin>>sno;
    int i;
    for(i=0; i<n; i++)
    {
        if(sno==stu[i].sno)
        {
            b=stu[i].calculate();
            if(b>=80&&b<85)
                cout<<"恭喜"<<stu[i].name<<"获得三等奖学金，数额为750"<<endl;
            else if(b>=85&&b<90)
                cout<<"恭喜"<<stu[i].name<<"获得二等奖学金，数额为1500"<<endl;
            else if(b>=90)
                cout<<"恭喜"<<stu[i].name<<"获得一等奖学金，数额为3000"<<endl;
            else
                cout<<"该生未获得奖学金，请继续努力"<<endl;
            return ;
        }
    }
    cout<<"查无此人"<<endl;
}

int main()
{
    system("color F0");
    student stu[100],*CH;
    guanli a;
    CH=stu;
    a.init(stu);
    int i,j;
loop:
    a.print();
    cin>>i;
    switch(i)
    {
    case 1:
        a.LuRu(CH);
        j=a.goon();
        if(j==1)
            goto loop;
        else
            break;
    case 2:
        a.show(CH);
        j=a.goon();
        if(j==1)
            goto loop;
        else
            break;
    case 3:
        a.find(CH);
        j=a.goon();
        if(j==1)
            goto loop;
        else
            break;
    case 4:
        break;

    }
    return 0;
}
