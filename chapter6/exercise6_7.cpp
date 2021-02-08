#include<iostream>

int call_time()
{
	static int cnt = 0;
	return cnt++;
}

int main()
{
	for (int i = 0; i < 5; ++i) {
		std::cout << call_time() << std::endl;
	}

	return 0;
}