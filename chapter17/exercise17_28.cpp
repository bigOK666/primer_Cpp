#include<random>
#include<iostream>
using namespace std;
unsigned rand_unsig()
{
	static default_random_engine e;
	return e();
}

int main()
{
	for (int i = 0; i != 10; ++i) {
		cout << rand_unsig() << endl;
	}
}