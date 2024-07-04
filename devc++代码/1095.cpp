#include<bitsdc++.h>
using namespace std;
int main() {
	char week[7][4]= {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char a[100],b[100],c[100],d[100];
	int tag=0;
	int weeka;
	int hour=0,min;
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	scanf("%s",d);
	int i,j,k;
	for(i=0; i<strlen(a)&&i<strlen(b); i++) {
		for(j=0;i<strlen(a)&& j<strlen(b); j++) {
			if((a[i]>='A'&&a[i]<='N')||(a[i]>='0'&&a[i]<='9')) { //第一次遇见
				if(a[i]>='A'&&a[i]<='G'&&tag==0) {
					if(a[i]==b[j]) {
						{
							weeka=b[j]-'A'+1;
							tag=1;break;
						}
					}
				}
				if(a[i]>='A'&&a[i]<='N'&&tag==1) {
					if(a[i]==b[j]&&tag==1) {
						if(a[i]>='0'&&a[i]<='9'&&tag==1) {
							hour=a[i]-'0';tag=66;
						} 
						else if(a[i]>='A'&&a[i]<='N'&&tag==1) {
						hour=a[i]-'A'+10;tag=66;}
					}
				}
			}

		}
	}

	for(i=0; i<strlen(c)&&i<strlen(d); i++) {
		if((c[i]>='A'&&c[i]<='Z')||(c[i]>='a'&&c[i]<='z')) {
			if(c[i]==d[i]){
				min=i;break;
			}
		}
	}
	printf("%c%c%c %02d:%02d\n",week[weeka-1][0],week[weeka-1][1],week[weeka-1][2],hour,min);

	return 0;
}
