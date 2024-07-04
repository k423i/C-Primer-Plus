#include  <bits/stdc++.h>
using namespace std;
int min(int a,int b){
	if(a>b) return b;
	else return a;
}
void reduce(int &a,int &b){
	int i=2;
	for(i=2;i<=min(a,b);i++){
		if((a%i==0)&&(b%i==0)){
			a/=i;b/=i;
			i=2;
		}
	}
}
int main()
{
	int a,b;
	cin>>a>>b;
	reduce(a,b);
	cout<<a<<b;
}
