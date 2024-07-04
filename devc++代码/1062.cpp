#include  <bits/stdc++.h>
using namespace std;
int min(int a,int b){
	if(a>b) return b;
	else return a;
}
int reduce(int &a,int &b){
	int i=2;
	int y=b;
	for(i=2;i<=min(a,b);i++){
		if((a%i==0)&&(b%i==0)){
			a/=i;b/=i;
			i=2;
		}
	}
	if(y!=b) return 1;//经过约分，返回1 
	return 0;
}
int main(){
	int n1,m1,n2,m2,k;
	int tag=0;
	
	int a[1000];
	int a0=0,b0=0;
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
	int u=k;
	double s1=n1*1.0/m1;
	double s2=n2*1.0/m2;
	if(s1>s2) swap(s1,s2);//确保s1<s2 
	double ko;
	int i=1;
	while(ko<s2){
		ko=i*1.0/k;

		if((ko>s1)&&(ko<s2)){
			a[a0++]=i;
		}
		i++;
	}
	int flag=0;
	for(int i=0;i<a0;i++){
		int o=a[i];
		if(reduce(a[i],k)){
			continue;
		}
	
		if(flag) cout<<" "<<o<<"/"<<u;
		else cout<<o<<"/"<<u;
		flag++;
	}
	return 0;
}
