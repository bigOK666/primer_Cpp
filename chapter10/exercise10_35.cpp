#include<vector>
#include<iterator>
#include<iostream>

using namespace std;

int main()
{
	vector<int> v_i{ 1,2,3,4,5,6 };

	auto end = v_i.cend();

	while (end != v_i.cbegin()) {
		cout << *(--end);
	}



}