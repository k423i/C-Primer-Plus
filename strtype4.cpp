#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    char r[20];
    string s;
    cout<<"len r before"<<strlen(r)<<endl;
    cout<<"len s before"<<s.size()<<endl;
    cin.getline(r, 20);
    getline(cin, s);

    cout<<"char[] "<<r<<endl;
    cout<<"string "<<s<<endl;

    cout<<"len r after"<<strlen(r)<<endl;
    cout<<"len s after"<<s.size()<<endl;
    return 0;
}