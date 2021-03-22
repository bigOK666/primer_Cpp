#include<bitset>
#include<vector>
using namespace std;
int main()
{
	bitset<64> b1(0B1000000010000100101110);
	bitset<64> b2;
	vector<int> pos{ 1,2,3,5,8,13,21 };
	for (const auto i : pos) {
		b2.set(i);
	}


}