#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100000],b[100000],num[100000];
	int max=0;
	cin>>n;
	for(int u=0;u<n;u++){
		cin>>a[u];
		b[u]=a[u];
	}
	sort(a,a+n);
	int flag=0;
	for(int i=0;i<n;i++){
		if((a[i]==b[i])&&b[i]>max){
			num[flag++]=a[i];
		}
		if(b[i]>max) max=b[i];
	}
	cout<<flag<<endl;
	for(int i=0;i<flag;i++){
		if(i==0) cout<<num[i];
		else cout<<" "<<num[i];
	}
	cout<<endl;
	return 0;
}
