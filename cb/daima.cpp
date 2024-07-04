#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10],i;
    for(i=0;i<10;i++)
        a[i]=2021;
    int tag=0;
    for(i=1;;i++)
    {
        int tool=i;
        while(tool!=0)
        {
            int k=tool%10;
            tool/=10;
            a[k]--;
            if(a[k]==0) {tag=1;break;}
        }
        if(tag==1) {cout<<i;break;}
    }
}
