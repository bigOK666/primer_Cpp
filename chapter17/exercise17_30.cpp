#include<random>
#include<iostream>
using namespace std;
unsigned rand_unsig(unsigned ui, unsigned minNr, unsigned maxNr)
{
	static default_random_engine e(ui);
	static uniform_int_distribution<unsigned> u(minNr, maxNr);
	return u(e);
}

int main()
{
	unsigned inNr = 0;
	cin >> inNr;
	for (int i = 0; i != 10; ++i) {
		cout << rand_unsig(inNr, 0, 100) << endl;
	}
}