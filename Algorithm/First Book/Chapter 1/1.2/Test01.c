#include <stdio.h>
#include <math.h>
int main()
{
    const double pi = 4.0 * atan(1.0);
    // const �Ĺؼ��ֱ�����ֵ�ǲ��ɱ��
/*    ������: atan
    �� ��: �����к���(C++)
    �� ��: double atan(double x);
    �� ��: -��~+��
    (ע����������ʽ�����ķ�Χ��ʵ�����뷶ΧΪdouble�͵ķ�Χ������ֵȡֵ��ΧΪ -1.7976E+308 �� -4.94065645841246544E-324����ֵȡֵ��ΧΪ 4.94065645841246544E-324 �� 1.797693E+308)
    �� ��: -pi/2~pi/2
    ���룺1
    �����pi/4*/
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

