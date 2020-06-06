#include <cmath>


const int n = 1e8;

int sum1(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; ++i)
		sum += pow(-1, i);
	return sum;
}

int sum2(int n)
{
	if (n % 2)
		return -1;
	return 0;
}