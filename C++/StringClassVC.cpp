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
 //生成新字符串函数
void String:: Creat()
 {
	cout<<"Please input length of string:"<<endl;
	cin>>size;
	str = new char[size];
	cout<<"Please input string:"<<endl;
	cin>>str;
 }
//输出
void String::Display()
{ int i;
  for(i=0;i<size;i++)  cout<<str[i];
  cout<<endl;
}
//求子串
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
//插入运算:在串对象s的pos位置后插入一个串t
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
//删除 :删除串中的一个子串
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

//主函数

int main(int argc, char* argv[])
{  
	int pos,num,k;
   String s,s1,t;
   do{  cout<<"\n\n    1.生成字符串"  ;
        cout<<"\n\n    2.取子串";
        cout<<"\n\n    3.插入子串s1";
        cout<<"\n\n    4.删除子串";
        cout<<"\n\n    5.结束程序";
        cout<<"\n******************************** ";
        cout<<"\n    请输入你的选择(1,2,3,4,5)";  cin>>k;
  switch(k){
       case 1:{//cout<<"请输入一个字符串：";
               s.Creat();
               cout<<"字符串为：       ";     s.Display();
              }break;
       case 2:{ cout<<"请输入子串的截取位置pos:"<<endl;
                cin>>pos;
				cout<<"请输入子串长度num:"<<endl;
				cin>>num;
                t=s.SubString(pos,num);
                cout<<"你所取的子串为：　　"<<endl;  
				t.Display();
               }break;
       case 3:{ cout<<"请输入子串插入位置pos"<<endl;
                cin>>pos;
                //cout<<"请输入要插入的子串:  ";   
				s1.Creat();
                s.Insert(s1,pos);
                cout<<"插入后的字符串为：   ";  s.Display();
              }break;
       case 4:{ cout<<"请输入要删除子串的开始位置pos"<<endl;
               cin>>pos;
			   cout<<"请输入要删除子串长度num"<<endl;
			   cin>>num;
               s.Delete(pos,num);
               cout<<"删除后的字符串为：   ";
               s.Display();
             }break;
     default:break;
  } //switch
     cout<<"\n--------------------------------- ";
}while(k>=1&&k<5);
  cout<<"\n          再见!";
  cout<<"\n     按任意键，返回。";
  return 0;

}
