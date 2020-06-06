#include <iostream>
#include <ctime>

int sum1(int);
int sum2(int);

int main()
{
	time_t s, e, sumtime;
	s = clock();
	std::cout << "sum:" << sum2(2) << std::endl;
	e = clock();
	sumtime = e - s;
	std::cout << "time:" << sumtime << std::endl;
	return 0;
}