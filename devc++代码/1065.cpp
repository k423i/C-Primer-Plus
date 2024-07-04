#include <bits/stdc++.h>
using namespace std;
#define x 100000
int main(){
	int n;cin>>n;
	int a[x],b[x];
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	int m;cin>>m;
	int c[x];
	for(int i=0;i<m;i++)
		cin>>c[i];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(c[i]==a[j]){
				for(int k=0;k<m;k++){
					if((c[k]==b[j])&&(k!=i)){
						c[i]=x;c[k]=x;
						break;			
					}
				}
			}
			else if(c[i]==b[j]){
				for(int k=0;k<m;k++){
					if((c[k]==a[j])&&(k!=i)){
						c[i]=x;c[k]=x;
						break;
					}
				}
			}
		}
	}
	c[m]=x;
	sort(c,c+m);
	int i;
	for(i=0;c[i]!=x;i++);
	cout<<i<<endl;
	for(int j=0;j<i;j++){
		if(j==0) cout<<c[j];
		else cout<<" "<<c[j];
	}
	return 0;
}/*
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
*/
