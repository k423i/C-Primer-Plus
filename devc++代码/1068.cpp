#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
map<int, int> b;
int a[1001][1001], k[8][2] = {-1,1,0,1,1,1,-1,0,1,0,-1,-1,0,-1,1,-1};
int row, column, q, num = 0, x, y, g;
bool check(int x,int y) {
	for (int i = 0; i < 8; i++) {
		int xx = x + k[i][0];
		int yy = y + k[i][1];
		if (xx >= 0 && yy >= 0 &&xx<column&&yy<row&& abs(a[x][y] - a[xx][yy]) <= q)
			return false;
	}
	return true;
}
int main()
{
	bool flag = true;
	cin >> column >> row >> q;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++) {
				cin >> a[i][j];
				b[a[i][j]]++;
			}
		for(int i=0;i<row;i++)
			for (int j = 0; j < column; j++) {
				if (num > 1) {
					cout << "Not Unique";
					return 0;
				}
				else {
					if (b[a[i][j]]==1&&check(i,j)) {
						num++;
						if (flag) {
							x = i;
							y = j;
							g = a[i][j];
							flag = false;
						}
					}
				}
			}
	if(num>0)
		cout << "(" << y+1 << ", " << x+1 << ")" << ": " << g;
	if(num==0)
		cout << "Not Exist";
}
