#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()//gerchar()去除上一行之后的回车
{
	int N; cin >> N;
	long long i = 0;
	char a[1000000];
	int num[100000];
	int cnt = 0;
	int c = 0;

	//cin >> ch;
	//if (ch == ' ') cout << "===";
	//cout << ":" << ch << ":";
	//if (getchar() == '\n') cout << "+++";
	getchar();
	while (cnt != N)
	{
	    char s[100000];
		fgets(s,10000,stdin);
		strcat(a," ");
		strcat(a,s);

		cnt++;
	}
	i=strlen(a);

	for (int k = 0; k < i; k++)
	{
		if (a[k] != ' ' && a[k] != '\n')
		{
			int newk ;
			int number = 0;
			for (newk=k; a[newk] >='0' && a[newk] <='9'; newk++)//当下一个也是数字的时候
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
  /*
  6
164 178 108 109 180 155 141 159 104 182 179 118 137 184 115 124 125 129 168 196
172 189 127 107 112 192 103 131 133 169 158
128 102 110 148 139 157 140 195 197
185 152 135 106 123 173 122 136 174 191 145 116 151 143 175 120 161 134 162 190
149 138 142 146 199 126 165 156 153 193 144 166                                                                                                                 170 121 171 132 101 194 187 188
113 130 176 154 177 120 117 150 114 183 186 181 100 163 160 167 147 198 111 119
  */
