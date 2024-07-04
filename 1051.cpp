#include <cstdio>
#include <math.h>
int main()
{
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double s=a*cos(b)*c*cos(d)-a*sin(b)*c*sin(d);
	double q=a*cos(b)*c*sin(d)+c*cos(d)*a*sin(b);
	if(fabs(s) < 0.005) printf("0.00");
	else printf("%.2lf", s);
	if(fabs(q) < 0.005) printf("+0.00i");
	else if(q < 0) printf("%.2lfi", q);
	else printf("+%.2lfi", q);
} 
