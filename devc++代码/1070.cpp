#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int a[10000];
	memset(a,0,sizeof(int)*n);
	double sum=0;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	sum=a[0];
	for(int i=0;i<n;i++)
		sum=(sum+a[i])*1.0/2;
	
	cout<<(int)sum;

	return 0;
}
