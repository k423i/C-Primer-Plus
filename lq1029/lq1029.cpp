#include <iostream>
#include <algorithm>
using namespace std;
int main()//gerchar()去除上一行之后的回车
{
	int N; cin >> N;
	char ch;
	int i = 0;
	char a[10000000];
	int num[10000000];
	int cnt = 0;
	int c = 0;
	cin >> ch; a[0] = ch; i++;
	//cin >> ch;
	//if (ch == ' ') cout << "===";
	//cout << ":" << ch << ":";
	//if (getchar() == '\n') cout << "+++";
	while (cnt != N)
	{
		cin.get(ch);
		a[i++] = ch;
		if (ch == '\n') cnt++;
	}/*
	for (int s = 0; s < i; s++)
		cout << a[s];*/
	for (int k = 0; k < i; k++)
	{
		if (a[k] != ' ' && a[k] != '\n')
		{
			int newk = k;
			int number = 0;
			for (newk; a[newk] >='0' && a[newk] <='9'; newk++)//当下一个也是数字的时候
			{
				number = 10 * number + (a[newk] - '0');
				k++;
			}

			num[c++] = number;
		}
	}
	sort(num,num+c);
	

	int m, n;
	for (int s = 0; s < c; s++)//从第零个开始
	{
		if (num[s + 1] - num[s] == 2) m = num[s] + 1;
		if (num[s + 1] == num[s]) n = num[s];//重号ID
	}
	cout << m << " " << n;
}
/*2
  320    322        321    
  325   324       322     */