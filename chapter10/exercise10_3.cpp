#include<numeric>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<int> v_i{ 1,2,3,4,5,65 };
	int sum = accumulate(v_i.cbegin(), v_i.cend(), 0);
	cout << sum;
}