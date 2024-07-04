#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    int a[3]={2, 3, 4};
    cout<<a[0]+a[1]+a[2]<<endl;

    char name1[3];
    char name2[15];
    cout<<"input name1"<<endl;
    cin.getline(name1, 15);
    cout<<"input name2"<<endl;
    cin.getline(name2, 15);
    cout<<"name1="<<name1<<endl;
    cout<<"name2="<<name2<<endl;
    name2[3]='\0';
    cout<<"name2="<<name2<<endl;
    return 0;
}