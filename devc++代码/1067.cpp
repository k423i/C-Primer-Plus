#include <bits/stdc++.h>//�ﵽn��ʱ������������wrong password ��account locked 
using namespace std;
int main(){
	string password;
	string test;
	cin>>password;
	int cnt;cin>>cnt;
	getchar();
	int x=0;
	while(cnt!=x){
		getline(cin,test);//�õ�һ�ţ����ո� 
		x++;
		if(test==password){
			cout<<"Welcome in";
			break;
		}
		if(test=="#") break;
		else{
			cout<<"Wrong password: "<<test<<endl;
			if(cnt==x){
				cout<<"Account locked";
				break;
			}
		}
	}
	return 0;
}
/*
Correct%pw 2
correct%pw
Correct%pw
Correct%pw
whatisthepassword!
#
*/
