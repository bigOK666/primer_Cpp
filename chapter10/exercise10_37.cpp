#include<iterator>
#include<vector>
#include<algorithm>
#include<list>
#include<iostream>
using namespace std;

int main()
{
	vector<int> v_i{ 1,2,3,4,5,6,7,8,9,10 };
	list<int> l_i;
	copy(v_i.crbegin() + 3, v_i.crend()-2, back_inserter(l_i));

	ostream_iterator<int> out(cout, " ");

	copy(l_i.cbegin(), l_i.cend(), out);
}