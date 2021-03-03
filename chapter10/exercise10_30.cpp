#include<string>
#include<vector>
#include<iterator>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	istream_iterator<int> in_iter(cin), eof;
	vector<int> v_i;
	copy(in_iter, eof, back_inserter(v_i));

	sort(v_i.begin(), v_i.end());

	ostream_iterator<int> out_iter(cout, " ");

	copy(v_i.cbegin(), v_i.cend(), out_iter);
}