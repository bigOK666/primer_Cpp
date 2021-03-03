#include<string>
#include<vector>
#include<iterator>
#include<fstream>
#include<iostream>
using namespace std;
int main(int argc, char **argv)
{	
	ifstream infile(argv[1]);
	istream_iterator<string> in_iter(infile), eof;
	vector<string> v_s(in_iter,eof);

	ostream_iterator<string> out_iter(cout, " ");
	copy(v_s.cbegin(), v_s.cend(), out_iter);

}