#include<iostream>
using namespace std;

class Box
{
private:
      double length;   // ����
      double breadth;  // ���
      double height;
public:
    Box();
    int fun_1();
    void fun_2();

};
//̫������š���ǿ�Ļ��������������͹�֮�׶����Դ������Ǩ����������������֮�ã����ɹ�����������������
//�б��ذ���������½��ѹ�����ղ��亣����ͼ�䴩�������ʻ�Ŭ˹֮ǹ�ᴩ�Ľ�����������Щ����������ȸ��֣�
Box::Box(){
};

int Box::fun_1(){
    length = 12;
    breadth = 23;
    height = 33;

    return length*breadth*height;
}

void Box::fun_2()
{
    double volume = 0.0;
    length = 12;
    breadth = 23;
    height = 33;
    volume =length*breadth*height;

    cout << "Box3 �������"<< volume <<endl;
}


int main()
{
    Box Box1;        // ���� Box1������Ϊ Box
           // ���� Box2������Ϊ Box
   double volume = 0.0;     // ���ڴ洢���
volume = Box1.fun_1();
   cout << "Box3 �������"<< volume <<endl;

   Box1.fun_2();
   return 0;

}
