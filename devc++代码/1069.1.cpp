#include<bits/stdc++.h>
using namespace std;
const int N=1500;
char a[N][N];     //�Ѿ�������ľͲ�������� 
int main()
{
	map<string,int > mp;
	int i,n,m,k,t;
	scanf("%d%d%d",&n,&m,&k);
	getchar();
	for(i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		getchar();
	}
	if(k>n)          //��������������Χ 
	{
		cout<<"Keep going..."<<endl;
	}
	else
	{
		cout<<a[k]<<endl;     //û�г�����Χ���Ȱѵ�һ������� 
		mp[a[k]]=1;
		t=k+m;                //tΪ���k�������±� 
		while(t<=n)
		{
			if(mp[a[t]]==0)    //ȥ�أ���������Ĳ������ 
			{
				mp[a[t]]=1;
				cout<<a[t]<<endl;
				t=t+m;         //�������k���� 
			}
			else              //����Ѿ�������ˣ������������һ�� 
			{
				t=t+1;
			}
		}
	}
	return 0;
}
