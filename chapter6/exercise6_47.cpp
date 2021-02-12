#include<string>
#include<vector>
#include<iostream>
using std::string;
using std::vector;

using Itr = vector<string>::const_iterator;
void print(Itr b, Itr e) 
{
#ifndef NDEBUG
	std::cout << e - b << std::endl;
#endif
	if (b == e) {
		std::cout << "REACH THE END";
	}
	else {
		std::cout << *b << std::endl;
		return print(++b, e);
	}
}

int main()
{
	vector<string> v1 = { "This is a test", "T", "TTT" };
	print(v1.cbegin(), v1.cend());
}
