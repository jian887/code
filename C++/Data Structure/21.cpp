#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include<windows.h>

using namespace std;
static int n=0;
/*
 *	1.����ĳ��ѧ��ĳ���꼶ĳ��רҵ����ĩ�ɼ�
 *	2.�����������ѧ�ּ�
 *	3.���ս�ѧ�����������������Ƚ�ѧ��Ļ�����
 */



class exam //-----------------------------------�ɼ���
{
public:
    float Math;
    float English;
    float Java;
    float C;
    float CountScore;//�ܳɼ�
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
class student //---------------------------------ѧ����
{
public:
    float calculate();//��ѧ�����
public:
    string name;	  //����
    string sno;	      //ѧ��
    char sex[5];   	  //�Ա�
    int money;        //��ѧ������
    float XueFenJi;  //ѧ�ּ�
    final fianlexam;  //��ĩ���Գɼ�

};

float student::calculate()//����ѧ�ּ�������ѧ�ּ���ֵ
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
    void print();//��������
    void init(student *stu);//��ʼ��
    int goon();//��������
    void LuRu(student *stu);//¼��
    void show(student *stu);//�鿴��ѧ����Ϣ����
    void find(student *stu);//��ѯ���˽�ѧ��
};

void guanli::print()   //��������
{
    cout<<"��--------------------------------------��"<<endl;
    cout<<"��         �� ��ѧ�����ϵͳ ��	       ��"<<endl;
    cout<<"��  �T�T�T�T�T�T�T�T�T�T�T�T���������T�T�T�T�T�T�T�T�T�T�T�T    ��"<<endl;
    cout<<"��*********  1. ¼��ѧ����Ϣ *********��"<<endl;
    cout<<"��*********  2. �鿴��ѧ����Ϣ *********��"<<endl;
    cout<<"��*********  3. ��ѯ���˽�ѧ�� *********��"<<endl;
    cout<<"��*********  4. �˳�           *********��"<<endl;
    cout<<"��------------------------------------  ��"<<endl;
}
int guanli::goon()       //��ӡ����
{
    int a;
    cout<<"���������밴1���˳��밴0"<<endl;
    cin>>a;
    return a;
}
void guanli::LuRu(student *stu)        //¼��ѧ����Ϣ����
{
    float a,b,c,d,i;
    cout<<"����ѧ��������ѧ�ţ��Ա�"<<endl;
    cin>>stu[n].name>>stu[n].sno>>stu[n].sex;
    cout<<"��ѡ������"<<stu[n].name<<"�ĳɼ�"<<endl;
    cout<<"�����������ĩ�ɼ�--�밴--��ѧ Ӣ�� Java C++ ��˳�����룬����Ĭ��Ϊ0"<<endl;
    cin>>a>>b>>c>>d;
    stu[n].fianlexam.Math=a;
    stu[n].fianlexam.English=b;
    stu[n].fianlexam.Java=c;
    stu[n].fianlexam.C=d;
    ofstream p;
    p.open("G:\\������Ϣ.txt",ios::app);
    if(!p)
    {
        cout<<"��ʧ��"<<endl;
        //return 0;
    }
    p<<endl<<stu[n].name<<" "<<stu[n].sno<<" "<<stu[n].sex<<stu[n].fianlexam.Math<<" "<<stu[n].fianlexam.English<<" "<<stu[n].fianlexam.Java<<" "<<stu[n].fianlexam.C;
    n++;
}

void guanli::init(student *stu) //��ʼ��ѧ����Ϣ����
{
    ifstream p;//ifstream �Ǵ�Ӳ�̶����ڴ�
    int i;
    p.open("G:\\������Ϣ.txt");
    if(!p)
    {
        cout<<"��ʧ��"<<endl;
        //exit(0);
    }
    while(!p.eof())	 //eof() ������ļ������ļ�ĩβ������true
    {
        p>>stu[n].name>>stu[n].sno>>stu[n].sex>>stu[n].fianlexam.Math>>stu[n].fianlexam.English>>stu[n].fianlexam.Java>>stu[n].fianlexam.C;
        n++;
    }
    for(i=0; i<n; i++)
        stu[i].calculate();
    p.close();
}

void guanli::show(student *stu)     //�鿴��ѧ����Ϣ����
{
    int i;
    cout<<"����"<<" "<<"ѧ�ּ�"<<"   "<<"��ѧ��/Ԫ"<<endl;
    for(i=0; i<n; i++)
    {
        stu[i].calculate();
        cout<<stu[i].name<<" "<<stu[i].XueFenJi<<" "<<stu[i].money<<endl;
    }
}
void guanli::find(student *stu)     //�鿴���˽�ѧ��
{
    float b;
    cout<<"����������ѯѧ��ѧ��"<<endl;
    string sno;
    cin>>sno;
    int i;
    for(i=0; i<n; i++)
    {
        if(sno==stu[i].sno)
        {
            b=stu[i].calculate();
            if(b>=80&&b<85)
                cout<<"��ϲ"<<stu[i].name<<"������Ƚ�ѧ������Ϊ750"<<endl;
            else if(b>=85&&b<90)
                cout<<"��ϲ"<<stu[i].name<<"��ö��Ƚ�ѧ������Ϊ1500"<<endl;
            else if(b>=90)
                cout<<"��ϲ"<<stu[i].name<<"���һ�Ƚ�ѧ������Ϊ3000"<<endl;
            else
                cout<<"����δ��ý�ѧ�������Ŭ��"<<endl;
            return ;
        }
    }
    cout<<"���޴���"<<endl;
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
