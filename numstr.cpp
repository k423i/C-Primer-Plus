#include <iostream>
using namespace std;
int main()
{
    int year;
    cin>>year;
    cin.get();

    char add[80];
    cin.getline(add, 80);
    cout<<"yeear "<<year<<endl;
    cout<<"address "<<add<<endl;
    return 0;
}