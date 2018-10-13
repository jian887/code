#include <stdio.h>
#include <math.h>
int main()
{
    const double pi = 4.0 * atan(1.0);
    // const 的关键字表明其值是不可变的
/*    函数名: atan
    功 能: 反正切函数(C++)
    用 法: double atan(double x);
    输 入: -∞~+∞
    (注：受限于形式参数的范围，实际输入范围为double型的范围，即负值取值范围为 -1.7976E+308 到 -4.94065645841246544E-324，正值取值范围为 4.94065645841246544E-324 到 1.797693E+308)
    输 出: -pi/2~pi/2
    输入：1
    输出：pi/4*/
    double r, h, s1, s2, s;
    scanf("%lf %lf",&r,&h);
    s1 = r*pi*pi;
    s2 = 2*pi*r*h;
    s = s1*2.0 + s2;
    printf("Area = %0.3lf\n",s);
    return 0;
}

/*
3 4
Area = 134.616
2 3
Area = 77.178

*/

