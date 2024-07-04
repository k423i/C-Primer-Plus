#include <bits/stdc++.h>
using namespace std;
bool isprim(long long number)
{
	int i;
	if(number==0||number==1) return false;
	for(i=2;i<=sqrt(number);i++)
	{
		if(number%i==0) return false; 
	}
	return true;
}
void out(char *a,int m,int n)
{
	int i;
	int number=0;
	for(i=m;i<m+n;i++)
	{
		number=10*number+(a[i]-'0');
	}
	if(isprim(number))
	{
		for(i=m;i<m+n;i++)
		{
			if(a[i]=='0') cout<<0; 
			else break;
		}
	}
	cout<<number;
}

int main()
{
	
	long long number=0;
	int L,K;cin>>L>>K;

	int p;bool o;
	char a[100000];
	for( p=0;p<L;p++)
		cin>>a[p];
	int flag=0;
	

	for(int j=0;j<L-K+1;j++)
	{
		number=0;
		for(int i=j;i<j+K;i++)
		{
			number=10*number+(a[i]-'0');
		}
		if(isprim(number)) {
			
			out(a,j,K);
			break;
		}
	}
	if(!isprim(number))
		cout<<404;
} 
/*10 8
2000000002*/
