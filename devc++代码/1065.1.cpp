#include<iostream>
#include<algorithm> 
#include <bits/stdc++.h>
#include <set>
using namespace std;
int main(){
	int n,a,b,m;
	int couple[100000];
	memset(couple,-1,400000);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		couple[a] = b;
		couple[b] = a;//666
	}
	cin>>m;
	int guest[m];
	int isExist[100000];
	for (int i = 0; i < m; i++) {
		scanf("%d", &guest[i]);
		if (couple[guest[i]] != -1)
			isExist[couple[guest[i]]] = 1;
	}
	
	
	int flag=0;
	set<int> s;
	for (int i = 0; i < m; i++) {
		if (!isExist[guest[i]])
			s.insert(guest[i]);
	}
	printf("%d\n", s.size());
	for (auto it = s.begin(); it != s.end(); it++) {
		if (it != s.begin()) printf(" ");
		printf("%05d", *it);
	}
//	int s[100000];
//	for (int i = 0; i < m; i++) {
//		if (!isExist[guest[i]])
//			s[flag++]=guest[i];
//	}
//	cout<<flag<<endl;
//	sort(s,s+flag);
//	for(int i=0;i<flag-1;i++)
//		cout<<s[i]<<" ";
//	cout<<s[flag-1];	
}
