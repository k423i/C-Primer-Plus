#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    char r1[20];
    char r2[20]="r2r2r2r2r2r2";
    string s1;
    string s2="s2s2s2s2ss2";
    s1=s2;
    strcpy(r1, r2);

    s1+="+++s1+++";
    strcat(r1, "+r1+");

    int len1=s1.size();
    int len2=strlen(r1);

    cout<<"s1 "<<s1<<"contains "<<len1<<" chars"<<endl;
    cout<<"r1 "<<r1<<"contains "<<len2<<" chars"<<endl;
    return 0;
}