#include <iostream.h>
#include <conio.h>
#include <string.h>
class String
{public:
     String(){};
     ~String(){};
     String SubString(int pos,int num);
     void Insert(String t,int pos);
     void Delete(int pos,int num);
     void Creat();
     void Display();
  private:
     char *str;
     int size;
 };
 //�������ַ�������
void String:: Creat()
 {
	cout<<"Please input length of string:"<<endl;
	cin>>size;
	str = new char[size];
	cout<<"Please input string:"<<endl;
	cin>>str;
 }
//���
void String::Display()
{ int i;
  for(i=0;i<size;i++)  cout<<str[i];
  cout<<endl;
}
//���Ӵ�
String String::SubString(int pos,int num)
{ 
	String s;
	if(pos<0||pos>size||(pos+num>size&&num>0))
	{
		cout<<"pos or num is worry"<<endl;
		return s;
	}
	s.size = num;
	s.str = new char[num];
	strcpy(s.str , str+pos-1);
	return s;
}
//��������:�ڴ�����s��posλ�ú����һ����t
void String::Insert(String t,int pos)
{
	if (pos>0&&t.size>0){
		char *si = new char(t.size+size);
		strcpy(si,str);
		strcpy(si+pos-1 , t.str);
		strcpy(si+pos+-1+t.size , str+pos-1);
		str = si;
		size = t.size + size;
	}
	else{
		cout<<"pos is warry"<<endl;
		return ;
	}

}
//ɾ�� :ɾ�����е�һ���Ӵ�
void  String:: Delete(int pos,int num)
{ 
	if(pos>0&&num>0&&(pos+num)<=size)
	{
		char *sd = new char[size-num];
		strncpy(sd , str , pos-1);
		//sd[pos] = '\0';
		strcpy(sd+pos-1 , str+pos-1+num);
		str = sd;
		size = size-num;
	}
	else{
		cout<<"pos or num is warry"<<endl;
		return ;
	}




}

//������

int main(int argc, char* argv[])
{  
	int pos,num,k;
   String s,s1,t;
   do{  cout<<"\n\n    1.�����ַ���"  ;
        cout<<"\n\n    2.ȡ�Ӵ�";
        cout<<"\n\n    3.�����Ӵ�s1";
        cout<<"\n\n    4.ɾ���Ӵ�";
        cout<<"\n\n    5.��������";
        cout<<"\n******************************** ";
        cout<<"\n    ���������ѡ��(1,2,3,4,5)";  cin>>k;
  switch(k){
       case 1:{//cout<<"������һ���ַ�����";
               s.Creat();
               cout<<"�ַ���Ϊ��       ";     s.Display();
              }break;
       case 2:{ cout<<"�������Ӵ��Ľ�ȡλ��pos:"<<endl;
                cin>>pos;
				cout<<"�������Ӵ�����num:"<<endl;
				cin>>num;
                t=s.SubString(pos,num);
                cout<<"����ȡ���Ӵ�Ϊ������"<<endl;  
				t.Display();
               }break;
       case 3:{ cout<<"�������Ӵ�����λ��pos"<<endl;
                cin>>pos;
                //cout<<"������Ҫ������Ӵ�:  ";   
				s1.Creat();
                s.Insert(s1,pos);
                cout<<"�������ַ���Ϊ��   ";  s.Display();
              }break;
       case 4:{ cout<<"������Ҫɾ���Ӵ��Ŀ�ʼλ��pos"<<endl;
               cin>>pos;
			   cout<<"������Ҫɾ���Ӵ�����num"<<endl;
			   cin>>num;
               s.Delete(pos,num);
               cout<<"ɾ������ַ���Ϊ��   ";
               s.Display();
             }break;
     default:break;
  } //switch
     cout<<"\n--------------------------------- ";
}while(k>=1&&k<5);
  cout<<"\n          �ټ�!";
  cout<<"\n     ������������ء�";
  return 0;

}
