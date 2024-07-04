#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,n;cin>>m>>n;
	int a,b,x;cin>>a>>b>>x;
	int pic[500][500];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>pic[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(pic[i][j]>=a&&pic[i][j]<=b){
				pic[i][j]=x;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j!=0) cout<<" ";
			if(pic[i][j]>=100) cout<<pic[i][j];
			else if(pic[i][j]>=10) cout<<"0"<<pic[i][j];
			else cout<<"00"<<pic[i][j];
		}
		cout<<endl;
	}
	return 0;
}
/*
3 5 100 150 33
3 189 254 101 119
150 233 151 99 100
88 123 149 0 255
*/
