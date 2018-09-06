#include<stdio.h>
main()
{
	int a=10,b,c=9,g,e1;
	int *d,*e,*f;
	b=a;
	printf("%d",b);
	b=c;
	printf("%d",b);
	d=&g;
	*d=20;
	printf("%d",*d);
	e=&e1;
	*e=30;
	printf("%d",*e);
	d=e;
	*d=40;
	printf("%d",*e);

}
