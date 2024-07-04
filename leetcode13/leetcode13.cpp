#include <iostream>
#include <cstdlib>
using namespace std;
int romanToInt(char* s) {
    cout << "函数里的s是" << s<<"===";
    int i = 0;
    int sum = 0;
    while (s[i] != '\0')
    {
        if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')
        {
            if (s[i] == 'I')
            {
                if (s[i+1] == 'V')
                {
                    i += 2;
                    sum += 4;
                    continue;
                }
                else if(s[i+1] == 'X')
                {
                    i += 2;
                    sum += 9;
                    continue;
                }
                else
                {
                    sum += 1;
                    i++;
                    continue;
                }
            }
            else if (s[i] == 'X')
            {
                if (s[i + 1] == 'L')
                {
                    i += 2;
                    sum += 40;
                    continue;
                }
                else if (s[i + 1] == 'C')
                {
                    i += 2;
                    sum += 90;
                    continue;
                }
                else
                {
                    sum += 10;
                    i++;
                    continue;
                }
            }
            else
            {
                if (s[i + 1] == 'D')
                {
                    i += 2;
                    sum += 400;
                    continue;
                }
                else if (s[i + 1] == 'M')
                {
                    i += 2;
                    sum += 900;
                    continue;
                }
                else
                {
                    sum += 100;
                    i++;
                    continue;
                }
            }
        }
        else
        {
            if (s[i] == 'V')
            {
                sum += 5; 
                i++;
                continue;
            }
            else if (s[i] == 'L')
            {
                sum += 50;
                i++;
                continue;
            }
            else if (s[i] == 'D')
            {
                sum += 500;
                i++;
                continue;
            }
            else if (s[i] == 'M')
            {
                sum += 1000;
                i++;
                continue;
            }
        }
        
    }
    cout << "sum=" << sum;
    return sum;
}
int main()
{
    std::cout << "Hello World!\n";
    char* s=NULL;
    //s = new char[3];
    s = (char*)malloc(1000 * sizeof(char));

    
    cin >> s;
    //cout << s[0];

    int k = romanToInt(s);
    //cout << k;
    free(s);
}

