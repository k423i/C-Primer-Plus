#include  <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int r,im;int u;
	double sum[n];
	for(u=0;u<n;u++){
		cin>>r>>im;
		sum[u]=sqrt(pow(r,2)+pow(im,2));
	}
	sort(sum,sum+n);
	printf("%.2lf",sum[n-1]);
	return 0;
}
