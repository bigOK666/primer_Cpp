#include<string>
#include<algorithm>
#include<list>
#include<iostream>
#include<iterator>
using namespace std;
void elimDups(list<string> &l_s)
{
	l_s.sort();
	l_s.unique();
}

int main()
{
	list<string> l_s{ "this", "is", "a", "test", "this", "is", "test" };

	elimDups(l_s);

	ostream_iterator<string> out(cout, " ");

	copy(l_s.cbegin(), l_s.cend(), out);
}
