#include<iostream>
#include<map>
using namespace std;
map<int,char>mp;//����map���� 
int main()
{
	//���鷽ʽ���� 
	mp[1]='a';
	mp[1]='b';//key�������ظ�,�ٴβ����൱���޸�value��ֵ 
	mp[2]='a'; 
	mp[3]='b';
	mp[4]='c';
	cout<<"����keyֵ�����Ӧ��valueֵ"<<mp[1]<<endl;
	cout<<"�޷�����value���keyֵ"<<mp['b']<<endl;
	
	//ͨ���ؼ���keyɾ��Ԫ�� 
	mp.erase('b');
	
	//insert()��ʽ����
	mp.insert(map<int,char>::value_type(5,'d')); 
	
	//���������С 
	int s=mp.size();
	cout<<s<<endl;
	
	//�������map�е�Ԫ�� 
	map<int,char>::iterator it=mp.begin();
	while(it!=mp.end())
	{
		cout<<"key:"<<it->first<<" "; 
		cout<<"value:"<<it->second<<endl;;
		it++;
	}
	it=mp.find(1);//������ֵΪ1��Ԫ�� 
	/*���ü�ֵ���ڣ��򷵻ظü�ֵ���ڵ�
	  ������λ�ã��������򷵻�end()������λ�� 
	*/
	if(it!=mp.end())
	{
	    cout<<"���ڼ�ֵΪ1��Ԫ��"<<endl;
	}
	//cout<<it->first<<it->second<<endl;	
	mp.clear();//������� 
	cout<<mp.size()<<endl;
}
