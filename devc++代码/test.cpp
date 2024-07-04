#include <bits/stdc++.h>
using namespace std;
int search(string ren[],string hR[],int m,int j){
	for(int i=1;i<=m;i++){
		if(ren[j]==hR[i]) return 1;
	}
	return 0;
}
int isEmpty(string s[],int m){
	for(int i=1;i<=m;i++){
		if(s[i]!=NULL) return 1;
	}
	return 0;
}
int main(){
	string ren[10];
	string s[10];	
	cout<<isEmpty(s,10);
//	for(int i=1;i<=5;i++) 
//		cin>>ren[i]>>s[i];
		
//	cout<<search(ren,s,5,3);
	
	
}
/*
asd 5
dsa 6
sds asd
ds956wd sds
s3 3
*/
