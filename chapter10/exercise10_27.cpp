#include<vector>
#include<algorithm>
#include<iterator>
#include<list>
#include<iostream>
using namespace std;
int main()
{
	vector<int> v_i{ 1,2,3,3,4,2,5,5,8 };
	list<int> l;

	sort(v_i.begin(), v_i.end());

	unique_copy(v_i.begin(), v_i.end(), back_inserter(l));

	for_each(l.cbegin(), l.cend(), [](int i) {cout << i << endl; });
}