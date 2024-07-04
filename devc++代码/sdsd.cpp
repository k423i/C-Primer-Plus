#include <bits/stdc++.h>
using namespace std;
int main(){
	set<int> s;
	for(int y=7;y>0;y--){
		s.insert(y);
	}
	s.insert(5);
	for(auto it=s.begin(); it!=s.end(); ++it){
		cout<<*it<<endl;
	}
}
