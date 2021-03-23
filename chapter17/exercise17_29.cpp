#include<random>
#include<iostream>
using namespace std;
unsigned rand_unsig(unsigned ui)
{
	static default_random_engine e(ui);
	return e();
}

int main()
{
	unsigned inNr = 0;
	cin >> inNr;
	for (int i = 0; i != 10; ++i) {
		cout << rand_unsig(inNr) << endl;
	}
}