#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> s;
	s.insert(4);
	s.insert(2);
	s.insert(1);
	s.insert(34);
	s.insert(45);
	for(auto it=s.begin();it!=s.end();++it){
		cout<<*it<<endl;
	}
	return 0;
} 
