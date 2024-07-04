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
		if(s[i].size()!=0) return 1;
	}
	return 0;
}
int main(){
	int m,n,s;cin>>m>>n>>s;//总人数，间隔人数，第一个中奖者的id 
	string haveReward[m+1];
	string ren[m+1];
	int cnt=0;
	for(int i=1;i<=m;i++)
		cin>>ren[i];

	int u=1;
//	for(int i=1;i<=m;i++)
//		cout<<ren[i]<<endl;
	int flag=0;
	int count=0;int cp=0;int p=0;
	for(int i=1;i<=m;i++){
//		cout<<i<<endl;
		if(i==s+cnt*n+count){ 
			if(!search(ren,haveReward,m,i)){ 
				cnt++;
				if(p=999){
					cout<<"S"<<ren[i]<<endl;
					p=0;
				}
				haveReward[u++]=ren[i];
				cout<<"S"<<ren[i]<<endl;
				count=0;
			}
			else {
				flag++;
//				cout<<flag<<endl;
				continue;
			} 
		}
		if(flag){
			if(!search(ren,haveReward,m,i)){
//				cnt++;
				
				//有相同的往后挪 
//				cout<<"count:"<<count<<endl;
				haveReward[u++]=ren[i];
				cout<<ren[i]<<endl;
				flag=0;
				p=999;
				count=0;
				cout<<"i:"<<i<<"cnt:"<<cnt<<endl;
			}
			else count++;
		}
	}
	if(!isEmpty(haveReward,m)) cout<<"Keep going...";
	return 0;
}
/*
10 3 1
a
a
a
a
a
a
a
a
a
c
*/
/*
10 3 1
a
b
c
a
a
a
c
d
b
m
*/
