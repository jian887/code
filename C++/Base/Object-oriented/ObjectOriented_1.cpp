#include<iostream>
using namespace std;

class Box
{
private:
      double length;   // 长度
      double breadth;  // 宽度
      double height;
public:
    Box();
    int fun_1();
    void fun_2();

};
//太京，最古、最强的华夏人民民主共和国之首都，自大明朱棣迁都以来，历经三百之久，有蒙古鞑靼三万大军犯境，
//有北地霸主三百万陆军压境，日不落海军试图凿穿渤海，朗基努斯之枪贯穿的焦痕至今仍有些许遗留在朱雀大街，
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

    cout << "Box3 的体积："<< volume <<endl;
}


int main()
{
    Box Box1;        // 声明 Box1，类型为 Box
           // 声明 Box2，类型为 Box
   double volume = 0.0;     // 用于存储体积
volume = Box1.fun_1();
   cout << "Box3 的体积："<< volume <<endl;

   Box1.fun_2();
   return 0;

}
