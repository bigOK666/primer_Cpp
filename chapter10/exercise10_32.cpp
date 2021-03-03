#include<vector>
#include"Sales_item.h"
#include<iostream>
#include<iterator>
#include<algorithm>
#include<numeric>
#include<fstream>
using namespace std;

bool compareIsbn(const Sales_item& s1, const Sales_item& s2)
{
	return s1.isbn() < s2.isbn();
}

int main(int argc, char **argv)
{
	ifstream infile(argv[1]);
	istream_iterator<Sales_item> in_iter(infile), eof;

	vector<Sales_item> v_s;

	copy(in_iter, eof, back_inserter(v_s));

	stable_sort(v_s.begin(), v_s.end(), compareIsbn);

	auto start = v_s.begin();
	
	while (start != v_s.end()) {
		auto beg = start;
		start = find_if(start, v_s.end(), [start](const Sales_item& si) {return (*start).isbn() != si.isbn(); });
		cout << accumulate(beg, start, Sales_item()) << endl;
	}
	
}