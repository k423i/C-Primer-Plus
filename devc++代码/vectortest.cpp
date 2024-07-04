#include <bits/stdc++.h>
using namespace std;
void pr(vector<int> v1){
	for(vector<int>::iterator it=v1.begin();it!=v1.end();++it){
		cout<<*it<<endl; 
	}
}
int main(){
	vector<int> v1;
	int arr[]={10,20,30,40};
	int arr1[]={100,200,300,400};
	vector<int> v2(arr,arr+sizeof(arr)/4);
	vector<int> v3(v2.begin(),v2.end());
	vector<int> v4(v3);
	vector<int> v5(arr1,arr1+sizeof(arr1)/4);
	vector<int> v6;
	
	pr(v4);
	pr(v5);
	
	v5.swap(v4);
	cout<<"==============="<<endl;
	pr(v4);
	pr(v5);
	
	return 0;
}
