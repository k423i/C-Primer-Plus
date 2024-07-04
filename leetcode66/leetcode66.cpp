#include <iostream>
using namespace std;

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	*returnSize = digitsSize;
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			digits[i]++;
			return digits;
		}
		digits[i] = 0;
	}//能出循环则代表全是9
	int d = digitsSize + 1;
	*returnSize = digitsSize + 1;
	int *temp = (int*)malloc(d * sizeof(int));
	memset(temp, 0, sizeof(int) * d);
	temp[0] = 1;
	return temp;
}
		