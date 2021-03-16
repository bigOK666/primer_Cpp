#include"exercise14_37.h"
#include<algorithm>
#include<list>
#include<iterator>
#include<iostream>
int main()
{
	std::list<int> l_i{ 1,2,3,3,3,3,3,5};

	std::replace_if(l_i.begin(), l_i.end(), isEqual(3), 5);
	std::ostream_iterator<int> out(std::cout, " ");
	std::copy(l_i.cbegin(), l_i.cend(), out);

}