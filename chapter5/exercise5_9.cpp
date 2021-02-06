#include<iostream>
using std::cin;
using std::cout;
int main()
{
	unsigned volCnt = 0;
	char in;
	while (cin >> in)
	{
		if (in == 'a' || in == 'e' || in == 'i' || in == 'o' || in == 'u') {
			++volCnt;
		}
	}

	cout << volCnt;
}