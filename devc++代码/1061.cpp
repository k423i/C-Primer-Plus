#include  <bits/stdc++.h>
using namespace std;
int main(){
	
	int n,m;cin>>n>>m;
	int x;
	int sum=0;
	int a[100];//����ÿ������� 
	int b[100];//����ÿ�����ȷ�� 
	for(int u=0;u<m;u++)
		cin>>a[u];
	for(int u=0;u<m;u++)
		cin>>b[u];
	for(int y=0;y<n;y++){//n��ѧ��
		sum=0;
		for(int o=0;o<m;o++){//m����Ŀ 
			cin>>x;
			if(x==b[o]) sum+=a[o];
		}
		cout<<sum<<endl;
	}
	return 0;
}
