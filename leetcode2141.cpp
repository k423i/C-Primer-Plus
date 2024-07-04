#include <bits/stdc++.h>
using namespace std;
bool ok(vector<int> &batteries,vector<int> &sums,long time,int num);
long long maxRunTime(int n, vector<int> &batteries) {
    long tot = accumulate(batteries.begin(), batteries.end(), 0L);
    vector<int> sums(batteries.size());//前缀和数组
	sums[0]=batteries[0];
	for(int i=1;i<batteries.size();i++){
		sums[i]=sums[i-1]+batteries[i];
	} 

    long l=0,m=0,r=sums[batteries.size()-1]/n,ans=-1;
    	while(m<=r){
		m=(l+r)/2;
		if(ok(batteries,sums,m,n)){//如果能满足m分钟 
			ans=m;
			l=m+1;
		}
		else r=m-1;
	}
	return ans;
}
bool ok(vector<int> &batteries,vector<int> &sums,long time,int num){
	int l=0,m=0,r=batteries.size()-1,left=batteries.size();
	while(l<=r){
		m=(l+r)/2;
		if(batteries[r]>=time){
			left=m;r=m-1;
		}
		else l=m+1;
	}
	num-=batteries.size()-left;//除开大电池的电脑
	long rest;
//	long rest=left==0?0:sums[left-1];
	if(left==0) rest=0;
	else rest=sums[left-1];
	if(time*(long)num<=rest) return true;
	return false;
}

int main(){
	vector<int> s;
	s.push_back(3);
	s.push_back(3);
	s.push_back(3);
	cout<<maxRunTime(2,s);
	return 0;
}
