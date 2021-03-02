#include<algorithm>
#include<list>
#include<iostream>
using namespace std;

int main()
{
	list<int> l_i{ 1,2,3,4,5,6,76 };

	fill_n(l_i.begin(), l_i.size(), 0);

	if (find(l_i.cbegin(), l_i.cend(), 6) == l_i.cend()) {
		cout << "All replaced";
	}
	else {
		cout << *(l_i.cbegin());
	}

}