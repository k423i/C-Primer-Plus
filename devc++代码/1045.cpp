#include<bits/stdc++.h>
using namespace std;
int leftcompare(int a[],int i){
	int flag=0;
	if(i==0) return 1;
	for(int s=0;s<i;s++){
		if(a[s]>a[i]) return 0;
	}
	return 1;
}
int rightcompare(int a[],int i,int n){
	int flag=0;
	if(i==n-1) return 1;
	for(int s=i;s<n;s++){
		if(a[s]<a[i]) return 0;
	}
	return 1;
}

int main(){
	
	int n,a[100000],b[100000];
	cin>>n;
	for(int u=0;u<n;u++){
		cin>>a[u]; 
	}
	int j=0;
	int k=a[0],kp=a[n-1];
	for(int i=0;i<n;i++){
		if(leftcompare(a,i)){
			if(rightcompare(a,i,n)){
				
				b[j++] = a[i];
			}
		}
	}
	sort(b,b+j);
	cout<<j<<endl;
	if(j!=0){
	for(int y=0;y<j;y++){
		if(y==0) cout<<b[y];
		else cout<<" "<<b[y];	
	}}
	else cout<<endl;
	return 0;
		
}
