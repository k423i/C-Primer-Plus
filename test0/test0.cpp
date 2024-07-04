#include <iostream>
#include <cstring>
using namespace std;
class String
{
private:
    char *stg;
public:
    String();
    ~String();
    String(const char *s);
    String(String &p);
    String& operator=(String &p);
    String& operator=(const char *p);
    String& operator+=(String &p);
    friend String& operator+(String &p1,String &p2);
    char& operator[](int m);
    friend bool operator==(String &p1,String &p2);
    friend bool operator<(String &p1,String &p2);
    friend istream& operator>>(istream &in,String &p);
    friend ostream& operator<<(ostream &out,String &p);
    int Length();
    void show()const
    {
        cout<<stg<<endl;
    }
};
String::String()
{
    stg=NULL;
}
String::String(const char *s)
{
    stg=new char[strlen(s)+1];
    strcpy(stg,s);
}
String::String(String &p)
{
     stg=new char[strlen(p.stg)+1];
     strcpy(stg,p.stg);
}
String& String::operator=(String &p)
{
    if(stg!=NULL)
    {
        delete []stg;
    }
    stg=new char[strlen(p.stg)+1];
    strcpy(stg,p.stg);
    return *this;
}
String& String::operator=(const char *p)
{
    if(stg!=NULL)
    {
        delete []stg;
    }
    stg=new char[strlen(p)+1];
    strcpy(stg,p);
    return *this;
}
String& String::operator+=(String &p)
{
    char *old;
    old=new char[strlen(stg)+1];
    strcpy(old,stg);
    delete []stg;
    stg=new char[strlen(old)+strlen(p.stg)+1];
    strcpy(stg,old);
    delete []old;
    strcat(stg,p.stg);
    return *this;
}
char& String::operator[](int m)
{
    return stg[m];
}
String::~String()
{
    if(stg!=NULL)
        delete []stg;
}
String& operator+(String &p1,String &p2)
{
    p1+=p2;
    return p1;
}
bool operator==(String &p1,String &p2)
{
   if(strcmp(p1.stg,p2.stg)==0)
    return 1;
   else
    return 0;
}
bool operator<(String &p1,String &p2)
{
    if(strcmp(p1.stg,p2.stg)<0)
    return 1;
   else
    return 0;
}
istream& operator>>(istream &in,String &p)
{
    char c[100];
    in>>c;
    p.stg=new char[strlen(c)+1];
    strcpy(p.stg,c);
    return in;
}
ostream& operator<<(ostream &out,String &p)
{
    out<<p.stg<<endl;
    return out;
}
int String::Length()
{
    return strlen(stg);
}
int main()
{
    String s1("Help!"),s2("Good!"),s3(s2),s4,s5;
    cout<<"s1=" <<s1<<endl;
    s3="Hello!";
    cout<<"s3="<<s3<<endl;
    s3=s2;
    cout<<"s3="<<s3<<endl;
    s3 += s2;
    cout << "s3=" << s3 << endl;
    cin >> s4;
    cout << "s4=" << s4 << endl;
    s5 = s3 + s4;
    cout << "s5=" << s5 << endl;
    s5[0] = 'g';
    cout << "s5=" << s5 << endl;
    cout << "strlen(s5)=" << s5.Length() << endl;
    cout << boolalpha << (s3 == s1) << endl;
    cout << boolalpha << (s3 < s1) << endl;
    return 0;
}
