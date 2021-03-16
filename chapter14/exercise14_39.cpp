#include"exercise14_38.h"
#include<iostream>
#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{

	for (int i = 0; i < 9; ++i) {
		ifstream input(argv[1]);
		istream_iterator<string> s_iter(input);
		istream_iterator<string> eof;
		std::cout << "Word length " << i + 1 << " has " << count_if(s_iter, eof, isSize(i + 1)) << endl;
		input.close();
	}

	ifstream input(argv[1]);
	istream_iterator<string> s_iter(input);
	istream_iterator<string> eof;
	std::cout << "Word length greater or equal 10 has " << count_if(s_iter, eof, greaterSize(10)) << endl;
	input.close();
}