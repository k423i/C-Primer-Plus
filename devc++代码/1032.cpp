#include <bits/stdc++.h>
using namespace std;
struct sch
{
    int no,score;
    int zongfen;
};
int main()
{
    int n,i,j;
    scanf("%d",&n);
    struct sch s[n];
    int sc[100000];
    memset(sc,0,100000*4);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&s[i].no,&s[i].score);
        sc[s[i].no]+=s[i].score;
    }
    int max=-1,io;
    for(i=1;i<=n;i++)
    {
        if(max<sc[i]) {max=sc[i];io=i;}
    }
    printf("%d %d\n",io,max);
}

