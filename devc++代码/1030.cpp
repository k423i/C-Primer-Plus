#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,p,j=0;cin>>n>>p;
	long long cnt=0,max=0;
	long long a[n];//M<=mp 
	long long b[n];
	b[0]=0;
	memset(b,0,sizeof(long long)*n);
	for(long long i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(j=0;j<n;j++){
		cnt=0;
		for(long long i=j+max;i<n;i++){
			if(a[i] <= a[j] * p)
				cnt = i - j + 1;
				if(cnt > max){
					max = cnt;
				}
			else
				break;
	}
}
	if(j>0)	cout<<max<<endl;
	else cout<<0<<endl;
	return 0;
}

