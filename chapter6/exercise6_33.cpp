#include<vector>
#include<iostream>
using std::vector;

using Itr = vector<int>::const_iterator;
void print(Itr first, Itr end) {
	if (first == end) {
		std::cout << "That's all" << std::endl;
		
	}
	else {
		std::cout << *first << std::endl;
		return print(++first, end);
	}
		
	
}

int main()
{
	vector<int> v = { 1,2,3,4,5 };

	print(v.cbegin(), v.cend());
}