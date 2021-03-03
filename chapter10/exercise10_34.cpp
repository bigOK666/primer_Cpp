#include<iterator>
#include<iostream>
#include<vector>

using namespace std;
int main()
{
	ostream_iterator<int> out(cout, " ");
	vector<int> v_i{ 1,2,3,4,5,65 };

	copy(v_i.crbegin(), v_i.crend(), out);


}