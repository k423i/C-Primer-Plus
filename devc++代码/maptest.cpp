#include<iostream>
#include<map>
using namespace std;
map<int,char>mp;//定义map容器 
int main()
{
	//数组方式插入 
	mp[1]='a';
	mp[1]='b';//key不允许重复,再次插入相当于修改value的值 
	mp[2]='a'; 
	mp[3]='b';
	mp[4]='c';
	cout<<"根据key值输出对应的value值"<<mp[1]<<endl;
	cout<<"无法根据value输出key值"<<mp['b']<<endl;
	
	//通过关键字key删除元素 
	mp.erase('b');
	
	//insert()方式插入
	mp.insert(map<int,char>::value_type(5,'d')); 
	
	//输出容器大小 
	int s=mp.size();
	cout<<s<<endl;
	
	//遍历输出map中的元素 
	map<int,char>::iterator it=mp.begin();
	while(it!=mp.end())
	{
		cout<<"key:"<<it->first<<" "; 
		cout<<"value:"<<it->second<<endl;;
		it++;
	}
	it=mp.find(1);//搜索键值为1的元素 
	/*若该键值存在，则返回该键值所在的
	  迭代器位置，不存在则返回end()迭代器位置 
	*/
	if(it!=mp.end())
	{
	    cout<<"存在键值为1的元素"<<endl;
	}
	//cout<<it->first<<it->second<<endl;	
	mp.clear();//清空容器 
	cout<<mp.size()<<endl;
}
