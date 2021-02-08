#include<iostream>

int call_time(int start)
{
	int diff = 2;
	static int callCnt = 0;
	callCnt = start + diff + callCnt;

	return callCnt;

}

int main()
{
	int i;
	std::cin >> i;
	while (i > 0) {
		std::cout << call_time(i--)<<std::endl;
	}

	return 0;
}