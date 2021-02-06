#include<iostream>
using std::cin;
int main()
{
	//while
	int i = 0;
	while (cin>>i)
	{

	}
	//for
	for (int j = 0; j < 50; ++j) {

	}

	//while replaced by for
	for (; cin >> i;);

	//for replaced by while
	int j = 0;
	while (j < 50) { ++j; }

	return 0;
}